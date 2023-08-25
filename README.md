# VR Pizza Robot Data Collection Pipline

The pipline was designed to collect the pizza making data in real world Franka Research 2 Robot. The gripper can be the orginal 2-finger gripper or the qb soft hand research 2 teleprotated by sense glove Nova.

# Files

## TeleoperationUnity
location: `/home/xrobot/TeleoperationUnity`.
This folder contains the main component of the Teleoperation control codebase.  The packages we use to control the robot is [frankapy and franka interface](https://github.com/iamlab-cmu/frankapy) by IAMLAB at CMU. 

### VR_Teleoperation_Pizza.py
location:`/home/xrobot/TeleoperationUnity/frankapy/examples/VR_Teleoperation_Pizza.py`.
We intialize the arm and make teleoperation connection between VR Quest 2 and the control server.

### Teleoperation.py
location:`/home/xrobot/TeleoperationUnity/frankapy/examples/Teleoperation.py`.
The main logic behind the Teleoperation, using multiple threads to send data and recieve data between from server and VR application. 

### Utils
 - Reset arm and gripper
 location: `/home/xrobot/TeleoperationUnity/frankapy/scripts/reset_arm.py`
 - Run a pre-designed dynamic trajectory demo
 location: `/home/xrobot/TeleoperationUnity/frankapy/examples/run_dynamic_pose.py`
 - record and replay a dynamic trajectory demo
 location: `/home/xrobot/TeleoperationUnity/frankapy/examples/record_trajectory.py` and `/home/xrobot/TeleoperationUnity/frankapy/examples/run_recorded_trajectory.py`

## VR Teleperation VR Applications
Designed in Unity 21 for quest 2. This is an application for Pizza Robot Teleporation. It is built up on https://github.com/Abraham190137/TeleoperationUnity.

## qb softhand Teleporation (optional)
The work space of qb hand is locate at `/home/xrobot/qb_ws`.
If use qb softhand, remember to modified `USE_ROBOHAND` in VR_Teleoperation_Pizza.py to True. and `-g 0` in launch_VR_Tele.sh. 

## Data Collection codebase
location:`/home/xrobot/moveit_ws/XRobot/Code/codebase/src/pizza_robot/sync_data_collection.py`.

The script use threads to collect images from 4 camera using ROS and robot information using FrankaArm.

### Utils
 - Run Auto play without tracking to iterate through the recorded pose
 location: `/home/xrobot/moveit_ws/XRobot/Code/codebase/src/pizza_robot/auto_play.py`
 - Run and upate the auto play recording pose. The recorded pose are save at `/home/xrobot/moveit_ws/XRobot/Code/codebase/src/pizza_robot/save_poses.json`.
 location: `/home/xrobot/moveit_ws/XRobot/Code/codebase/src/pizza_robot/save_auto_play_poses.py`

# Teleportation Step

## Setup Server
- `bash launch_VR_Tele.sh`
Launch 3 Termials for franka interface. 
 - `bash launch_4_cameras_only_rgb.sh`
Launch 2 realsense D345i and 2 Azure Kinect DK camera with no depth information. The frequenze is 15 HZ.
 - `bash kill_terminals.sh`
Kill all the terminals.

## Start VR application
Run Telportation APP in the Quest 2 headset. Be ready in the Main Scene. Wait for the start up of `VR_Teleoperation_Pizza.py` After the udp connection is stable, press `Start`.
Press `A` for resume the teleportation. Press `B` for get back to main scene. If anything wrong happen, remember to first press A and then press B and wait for the start up of the python script. If the gripper can not move, press the left controller and try again.

## Teleportation and Save a file
- `python3 /home/xrobot/TeleoperationUnity/frankapy/examples/VR_Teleoperation_Pizza.py`
Start telepertation and the UDP connection for VR connection and server. If no messages, ctrl+C to quit. If no error happens, can continuely run it.
- `python3 /home/xrobot/moveit_ws/XRobot/Code/codebase/src/pizza_robot/sync_data_collection.py`
Run the script and start collecting data when the robot is in position. Run once for every task skills. Write the skill number as the task name. Press `Enter` to stop recording. Press `y` to save and `n` to delete the recoding.

# Auto-collect Step

## Setup Server
- `bash launch_VR_Tele.sh`
Launch 3 Termials for franka interface. 
 - `bash launch_4_cameras_only_rgb.sh`
Launch 2 realsense D345i and 2 Azure Kinect DK camera with no depth information. The frequenze is 15 HZ.
 - `bash kill_terminals.sh`
Kill all the terminals.

## Start and record
- `python3 /home/xrobot/moveit_ws/XRobot/Code/codebase/src/pizza_robot/auto_run.bash`
Number of iteration is how many tasks you want to complete.
For Mode, Enter 0 for single object task, Enter 1 for random combination of tasks.
