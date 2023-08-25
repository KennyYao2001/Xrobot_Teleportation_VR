# Control PC Ubuntu Setup Guide

This guide describes how to setup the Ubuntu 16.04 / 18.04 Realtime Kernel on the Control PC.

## Install Ubuntu 18.04
Follow the tutorial located [here](https://ubuntu.com/tutorials/tutorial-install-ubuntu-desktop) to install Ubuntu 18.04 on your computer.

## Realtime Kernel Installation
In order to communicate with the Franka Panda Research Arm at 1 kHz, we need Ubuntu to be patched with the PREEMPT_RT patch. This is also known as the “realtime kernel” patch. 

First, install required dependencies:
`sudo apt install build-essential bc curl ca-certificates fakeroot gnupg2 libssl-dev lsb-release libelf-dev bison flex`

Secondly, you need to pick a mainline kernel version that has a preempt_rt [“RT”] patch. What worked best was selecting the next closest RT kernel available to what was installed on the system. (List of RT versions: https://mirrors.edge.kernel.org/pub/linux/kernel/projects/rt/) 

Out of the box, Ubuntu 18.04.6 LTS comes with kernel “5.4”. So we picked 5.4.3 [here](https://mirrors.edge.kernel.org/pub/linux/kernel/projects/rt/5.4/older/).
You can identify what kernel version you are currently using with `uname -r`.

We will download both the mainline version of the kernel we want along with the RT patch, extract the mainline kernel and apply the RT patch, then compile the kernel and install it.

Create the directory and download the kernel files:
```
mkdir -p ~/Downloads/preempt_rt_5.4.3
cd ~/Downloads/preempt_rt_5.4.3
curl -SLO https://www.kernel.org/pub/linux/kernel/v5.x/linux-5.4.3.tar.xz
curl -SLO https://www.kernel.org/pub/linux/kernel/v5.x/linux-5.4.3.tar.sign
curl -SLO https://www.kernel.org/pub/linux/kernel/projects/rt/5.4/older/patch-5.4.3-rt1.patch.xz
curl -SLO https://www.kernel.org/pub/linux/kernel/projects/rt/5.4/older/patch-5.4.3-rt1.patch.sign
```

(In the patch directory [https://mirrors.edge.kernel.org/pub/linux/kernel/projects/rt/5.4/older/ in this case] you may see both “patch” and “patches” file. Use “patch” -- it’s one file that contains everything that’s needed.)
The .sign files are used to verify the files (if you’d like -- it’s optional).

Decompress tar files:
```
xz -d linux-5.4.3.tar.xz
xz -d patch-5.4.3-rt1.patch.xz
```

Apply the kernel patch:
```
tar xf linux-5.4.3.tar
cd linux-5.4.3/
patch -p1 < ../patch-5.4.3-rt1.patch
```

Start kernel configuration using the current kernel’s config:
`make oldconfig`

Select the default [hit enter] for everything EXCEPT the kernel preemption model. It will look like this:
```
Preemption Model
  1. No Forced Preemption (Server) (PREEMPT_NONE)
  2. Voluntary Kernel Preemption (Desktop) (PREEMPT_VOLUNTARY)
  3. Preemptible Kernel (Low-Latency Desktop) (PREEMPT__LL) (NEW)
  4. Preemptible Kernel (Basic RT) (PREEMPT_RTB) (NEW)
  5. Fully Preemptible Kernel (RT) (PREEMPT_RT_FULL) (NEW)
choice[1-5?]:
```
Input `5` to choose the full preemptible kernel.

Build the kernel where `N` represents the number of threads in your processor:
`fakeroot make -jN deb-pkg`

This will take some time.
Now, we want to install the new .deb packages, but not ones with `dbg` in the file name:

Installing the kernel .deb packages:
```
cd ..
sudo dpkg -i linux-headers-5.4.3-rt1_5.4.3-rt1-1_amd64.deb linux-image-5.4.3-rt1_5.4.3-rt1-1_amd64.deb linux-libc-dev_5.4.3-rt1-1_amd64.deb
```

Now, restart. If the RT kernel has been successfully installed, the following will confirm:
`uname -r` will show the new kernel: 5.4.3-rt1
`cat /sys/kernel/realtime` should show an output of “1”

Set real-time settings
```
sudo addgroup realtime
sudo usermod -a -G realtime $(whoami)
```

Add the following to: /etc/security/limits.conf (with sudo gedit or sudo <your favorite editor>)
```
@realtime soft rtprio 99
@realtime soft priority 99
@realtime soft memlock 102400
@realtime hard rtprio 99
@realtime hard priority 99
@realtime hard memlock 102400
```

Restart one final time.


## ROS Installation
Install ROS (using the desktop-full package) using this guide for Ubuntu 18.04: http://wiki.ros.org/melodic/Installation/Ubuntu

## Install CPU Monitoring Utilities
Now, we want to install some utilities and files that will maintain the correct CPU governor mode. (For reference, there are usually two CPU governor modes available: powersave and performance. We always want to run the arms in performance mode, which maintains the maximum CPU frequency. Powersave is great for laptops, not laboratory experiments. The following is adapted from https://askubuntu.com/questions/929884/how-to-set-performance-instead-of-powersave-as-default and https://askubuntu.com/questions/621184/how-to-make-cpupower-not-reset-after-each-restart)

Run the following terminal command:
`sudo apt install indicator-cpufreq cpufrequtils`

Restart and then confirm that indicator-cpufreq starts when logged in. You should see what looks like a CPU icon in the system toolbar, with a drop-down menu that shows the current CPU governor. You can select the performance mode here, but we will now add files to do this automatically.

Run the following terminal commands:
1. Define the default CPU governor:
`echo "GOVERNOR="performance"" | sudo tee /etc/default/cpufrequtils`

2. Restart cpufrequtils so that performance mode is selected:
`sudo /etc/init.d/cpufrequtils restart`

3. Create cpu.sh script that restarts cpufrequtils (see next step for what to add)
`sudo gedit /etc/init.d/cpu.sh`

4. Add the following lines to cpu.sh:
```
sleep 60 # Give CPU startup routines time to settle.
sudo /etc/init.d/cpufrequtils restart
```

5. Enable cpu.sh to be executable:
`sudo chmod +x /etc/init.d/cpu.sh`

6. Enable cpu.sh to be executed at startup:
`sudo update-rc.d cpu.sh defaults`

7. Opens /etc/rc.local for editing:
`sudo gedit /etc/rc.local`

8. Add the following lines to /etc/rc.local:
```
#!/bin/sh -e
#
# rc.local
#
# This script is executed at the end of each multiuser runlevel.
# Make sure that the script will "exit 0" on success or any other
# value on error.
#
# In order to enable or disable this script just change the execution
# bits.
#
# By default this script does nothing.

/etc/init.d/cpu.sh &

exit 0
```

In short, we have defined the default CPU governor, then created several processes for Ubuntu to automatically select this governor when you log in.

Reboot.

## Testing CPU Governor Mode
It is important to test that the correct CPU governor mode is automatically selected on startup, because using the wrong mode may adversely affect communications with the robot arms and thus experiments. We want this to be automatically set correctly when logging in to the computer and not have to deal with it.

From a computer reboot, log in to the computer.
Select the indicator-cpufreq icon to display the drop-down menu, but do not select anything. We will keep the menu open during this test.
Observe that the governor is currently set to performance.
After some time after login (30-60 seconds), a system process will change this to powersave. You will see this change automatically in the menu.

However, after about 90 seconds, you should observe that the governor automatically changes back to performance.
This happens because of the commands we added to the /etc/rc.local file!

If you observe that the governor properly gets changed to performance mode, then everything has been set up correctly.

It is expected from here on that you will not have to worry about the CPU governor. However, I would still double check at least for now before running experiments while we are still stabilizing and testing our system setup.

If you find that something is unexpectedly changing the CPU governor back to powersave, let Tim Lee know. We will need to debug and find out what that process is.
