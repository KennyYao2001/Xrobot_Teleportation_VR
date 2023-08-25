# Franka-Interface

This is a software package used for controlling and learning skills on the Franka Emika Panda Research Robot Arm.

More Detailed Installation Instructions and Robot Setup Instructions are available here: [https://iamlab-cmu.github.io/franka-interface](https://iamlab-cmu.github.io/franka-interface)

For the Franka Research 3, you will first need to download the FCI package from Franka World. Then in order to use the FCI, you must disable all of the safety features in the Watchman by first creating a Watchman account using the admin account and then logging into the Watchman account to delete all of the safety policies. Then the robot should be able to connect to the FCI.

To join the Discord community, click the link [here](https://discord.gg/r6r7dttMwZ).

## Requirements

* A computer with the Ubuntu 18.04 / 20.04 Realtime Kernel and at least 1 ethernet port.
* ROS Melodic / Noetic or ROS2 Foxy / Humble
* [Protocol Buffers](https://github.com/protocolbuffers/protobuf)

## Computer Setup Instructions

This library is intended to be installed on the computer that interfaces with the Franka (we call this the Control PC).
To use this library, refer to [FrankaPy](https://github.com/iamlab-cmu/frankapy), which can be run on any computer on the same ROS network and sends commands to `franka-interface`.

1. The Control PC should have an OS with real time kernel. The instructions for setting up a computer with the 18.04 Realtime Kernel from scratch are located here: [control pc ubuntu setup guide](old_docs/control_pc_ubuntu_setup_guide.md)
2. Instructions for setting up the computer specifically for Franka Robots is located here: [franka control pc setup guide](old_docs/franka_control_pc_setup_guide.md)

## Install ProtoBuf

We use both C++ and Python versions of protobufs so you would need to install Protobufs from source. 

Do `nproc` to find out how many cores you have, and use that as the `N` number in the `make` command below:

```shell
sudo apt-get install autoconf automake libtool curl make g++ unzip
wget https://github.com/protocolbuffers/protobuf/releases/download/v21.8/protobuf-all-21.8.zip
unzip protobuf-all-21.8.zip
cd protobuf-21.8
./configure
make -jN
make check -jN
sudo make install
sudo ldconfig
```

See detailed instructions [here](https://github.com/protocolbuffers/protobuf/blob/master/src/README.md)

## Installation

1. Clone Repo and its Submodules:

   ```bash
   git clone --recurse-submodules https://github.com/iamlab-cmu/franka-interface.git   
   cd franka-interface
   ```
   
All directories below are given relative to `/franka-interface`.

2. Clone LibFranka corresponding to your robot version. For example if your firmware is 3.x use the following command:
   ```bash
   bash ./bash_scripts/clone_libfranka.sh 3
   ```

   If you are using the Franka Research 3 use the following command:
   ```bash
   bash ./bash_scripts/clone_libfranka.sh 6
   ```


3. Build LibFranka
   ```bash
   bash ./bash_scripts/make_libfranka.sh
   ```

4. Build franka-interface
   ```bash
   bash ./bash_scripts/make_franka_interface.sh
   ```
   Once it has finished building, you should see an application named `franka_interface` in the build folder.

5. Build ROS Node franka_ros_interface

   Make sure that you have installed ROS Kinetic / Melodic already and have added the `source /opt/ros/kinetic/setup.bash` or `source /opt/ros/melodic/setup.bash` into your `~/.bashrc` file. Make sure you have also installed catkin-tools either globally or in a virtual environment using the command `pip install catkin-tools`.

   ```bash
   bash ./bash_scripts/make_catkin.sh
   ```

6. To allow asynchronous gripper commands, we use the franka\_ros package, so install libfranka and franka\_ros using the following command (Change melodic to kinetic if you are on Ubuntu 16.04:
   ```bash
   sudo apt install ros-melodic-libfranka ros-melodic-franka-ros
   ```
   
## Citation

If this library proves useful to your research, please cite the paper below::
```
@article{zhang2020modular,
title={A modular robotic arm control stack for research: Franka-interface and frankapy},
author={Zhang, Kevin and Sharma, Mohit and Liang, Jacky and Kroemer, Oliver},
journal={arXiv preprint arXiv:2011.02398},
year={2020}
}
```

## Issues

#### LibPoco issue

libFranka requires libPoco, which can be installed using `sudo apt-get install libpoco-doc libpoco-dev`. However, trying to build libFranka might still fail since `CMAKE` cannot run ` find_package(Poco)` since there doesn't exist `/usr/local/lib/cmake/Poco/PocoConfig.cmake`. This is a peculiarity of libPoco which installs in a weird way without providing an option for us to link against it. 

To fix this we have copied the `libPoco.cmake` file in `{franka-interface-dir}/cmake`, and we add the following line to the CMakeLists.txt

`list(INSERT CMAKE_MODULE_PATH 0 ${CMAKE_SOURCE_DIR}/cmake`

Do the following if you run run into `libfranka: Cannot load model library: Cannot load library`:

```sh
mkdir -p /usr/local/lib/cmake/Poco/
cp cmake/FindPoco.cmake /usr/local/lib/cmake/FindPoco.cmake
```
