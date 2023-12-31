// Generated by gencpp from file franka_interface_msgs/GetCurrentRobotStateCmdResponse.msg
// DO NOT EDIT!


#ifndef FRANKA_INTERFACE_MSGS_MESSAGE_GETCURRENTROBOTSTATECMDRESPONSE_H
#define FRANKA_INTERFACE_MSGS_MESSAGE_GETCURRENTROBOTSTATECMDRESPONSE_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <franka_interface_msgs/RobotState.h>

namespace franka_interface_msgs
{
template <class ContainerAllocator>
struct GetCurrentRobotStateCmdResponse_
{
  typedef GetCurrentRobotStateCmdResponse_<ContainerAllocator> Type;

  GetCurrentRobotStateCmdResponse_()
    : robot_state()  {
    }
  GetCurrentRobotStateCmdResponse_(const ContainerAllocator& _alloc)
    : robot_state(_alloc)  {
  (void)_alloc;
    }



   typedef  ::franka_interface_msgs::RobotState_<ContainerAllocator>  _robot_state_type;
  _robot_state_type robot_state;





  typedef boost::shared_ptr< ::franka_interface_msgs::GetCurrentRobotStateCmdResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::franka_interface_msgs::GetCurrentRobotStateCmdResponse_<ContainerAllocator> const> ConstPtr;

}; // struct GetCurrentRobotStateCmdResponse_

typedef ::franka_interface_msgs::GetCurrentRobotStateCmdResponse_<std::allocator<void> > GetCurrentRobotStateCmdResponse;

typedef boost::shared_ptr< ::franka_interface_msgs::GetCurrentRobotStateCmdResponse > GetCurrentRobotStateCmdResponsePtr;
typedef boost::shared_ptr< ::franka_interface_msgs::GetCurrentRobotStateCmdResponse const> GetCurrentRobotStateCmdResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::franka_interface_msgs::GetCurrentRobotStateCmdResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::franka_interface_msgs::GetCurrentRobotStateCmdResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::franka_interface_msgs::GetCurrentRobotStateCmdResponse_<ContainerAllocator1> & lhs, const ::franka_interface_msgs::GetCurrentRobotStateCmdResponse_<ContainerAllocator2> & rhs)
{
  return lhs.robot_state == rhs.robot_state;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::franka_interface_msgs::GetCurrentRobotStateCmdResponse_<ContainerAllocator1> & lhs, const ::franka_interface_msgs::GetCurrentRobotStateCmdResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace franka_interface_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::franka_interface_msgs::GetCurrentRobotStateCmdResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::franka_interface_msgs::GetCurrentRobotStateCmdResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::franka_interface_msgs::GetCurrentRobotStateCmdResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::franka_interface_msgs::GetCurrentRobotStateCmdResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::franka_interface_msgs::GetCurrentRobotStateCmdResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::franka_interface_msgs::GetCurrentRobotStateCmdResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::franka_interface_msgs::GetCurrentRobotStateCmdResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "b518dbe0aba9b1925588d18e42fb85fa";
  }

  static const char* value(const ::franka_interface_msgs::GetCurrentRobotStateCmdResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xb518dbe0aba9b192ULL;
  static const uint64_t static_value2 = 0x5588d18e42fb85faULL;
};

template<class ContainerAllocator>
struct DataType< ::franka_interface_msgs::GetCurrentRobotStateCmdResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "franka_interface_msgs/GetCurrentRobotStateCmdResponse";
  }

  static const char* value(const ::franka_interface_msgs::GetCurrentRobotStateCmdResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::franka_interface_msgs::GetCurrentRobotStateCmdResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "RobotState robot_state\n"
"\n"
"================================================================================\n"
"MSG: franka_interface_msgs/RobotState\n"
"# Franka robot state\n"
"# For more information about each field, look at robot_state.h here: \n"
"# https://github.com/frankaemika/libfranka/blob/master/include/franka/robot_state.h\n"
"std_msgs/Header header\n"
"float64[16] pose_desired\n"
"float64[16] O_T_EE \n"
"float64[16] O_T_EE_d\n"
"float64[16] F_T_EE\n"
"float64[16] EE_T_K\n"
"float64 m_ee\n"
"float64[9] I_ee\n"
"float64[3] F_x_Cee\n"
"float64 m_load\n"
"float64[9] I_load\n"
"float64[3] F_x_Cload\n"
"float64 m_total\n"
"float64[9] I_total\n"
"float64[3] F_x_Ctotal\n"
"float64[2] elbow\n"
"float64[2] elbow_d\n"
"float64[2] elbow_c\n"
"float64[2] delbow_c\n"
"float64[2] ddelbow_c\n"
"float64[7] tau_J\n"
"float64[7] tau_J_d\n"
"float64[7] dtau_J\n"
"float64[7] q\n"
"float64[7] q_d\n"
"float64[7] dq\n"
"float64[7] dq_d\n"
"float64[7] ddq_d\n"
"float64[7] joint_contact\n"
"float64[6] cartesian_contact\n"
"float64[7] joint_collision\n"
"float64[6] cartesian_collision\n"
"float64[7] tau_ext_hat_filtered\n"
"float64[6] O_F_ext_hat_K\n"
"float64[6] K_F_ext_hat_K\n"
"float64[6] O_dP_EE_d\n"
"float64[16] O_T_EE_c\n"
"float64[6] O_dP_EE_c\n"
"float64[6] O_ddP_EE_c\n"
"float64[7] theta\n"
"float64[7] dtheta\n"
"Errors current_errors\n"
"Errors last_motion_errors\n"
"float64 control_command_success_rate\n"
"uint8 ROBOT_MODE_OTHER=0\n"
"uint8 ROBOT_MODE_IDLE=1\n"
"uint8 ROBOT_MODE_MOVE=2\n"
"uint8 ROBOT_MODE_GUIDING=3\n"
"uint8 ROBOT_MODE_REFLEX=4\n"
"uint8 ROBOT_MODE_USER_STOPPED=5\n"
"uint8 ROBOT_MODE_AUTOMATIC_ERROR_RECOVERY=6\n"
"uint8 robot_mode\n"
"float64 robot_time\n"
"float64 gripper_width\n"
"float64 gripper_max_width\n"
"bool gripper_is_grasped\n"
"uint16 gripper_temperature\n"
"float64 gripper_time\n"
"bool is_fresh\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
"\n"
"================================================================================\n"
"MSG: franka_interface_msgs/Errors\n"
"bool joint_position_limits_violation\n"
"bool cartesian_position_limits_violation\n"
"bool self_collision_avoidance_violation\n"
"bool joint_velocity_violation\n"
"bool cartesian_velocity_violation\n"
"bool force_control_safety_violation\n"
"bool joint_reflex\n"
"bool cartesian_reflex\n"
"bool max_goal_pose_deviation_violation\n"
"bool max_path_pose_deviation_violation\n"
"bool cartesian_velocity_profile_safety_violation\n"
"bool joint_position_motion_generator_start_pose_invalid\n"
"bool joint_motion_generator_position_limits_violation\n"
"bool joint_motion_generator_velocity_limits_violation\n"
"bool joint_motion_generator_velocity_discontinuity\n"
"bool joint_motion_generator_acceleration_discontinuity\n"
"bool cartesian_position_motion_generator_start_pose_invalid\n"
"bool cartesian_motion_generator_elbow_limit_violation\n"
"bool cartesian_motion_generator_velocity_limits_violation\n"
"bool cartesian_motion_generator_velocity_discontinuity\n"
"bool cartesian_motion_generator_acceleration_discontinuity\n"
"bool cartesian_motion_generator_elbow_sign_inconsistent\n"
"bool cartesian_motion_generator_start_elbow_invalid\n"
"bool cartesian_motion_generator_joint_position_limits_violation\n"
"bool cartesian_motion_generator_joint_velocity_limits_violation\n"
"bool cartesian_motion_generator_joint_velocity_discontinuity\n"
"bool cartesian_motion_generator_joint_acceleration_discontinuity\n"
"bool cartesian_position_motion_generator_invalid_frame\n"
"bool force_controller_desired_force_tolerance_violation\n"
"bool controller_torque_discontinuity\n"
"bool start_elbow_sign_inconsistent\n"
"bool communication_constraints_violation\n"
"bool power_limit_violation\n"
"bool joint_p2p_insufficient_torque_for_planning\n"
"bool tau_j_range_violation\n"
"bool instability_detected\n"
"bool joint_move_in_wrong_direction\n"
;
  }

  static const char* value(const ::franka_interface_msgs::GetCurrentRobotStateCmdResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::franka_interface_msgs::GetCurrentRobotStateCmdResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.robot_state);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GetCurrentRobotStateCmdResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::franka_interface_msgs::GetCurrentRobotStateCmdResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::franka_interface_msgs::GetCurrentRobotStateCmdResponse_<ContainerAllocator>& v)
  {
    s << indent << "robot_state: ";
    s << std::endl;
    Printer< ::franka_interface_msgs::RobotState_<ContainerAllocator> >::stream(s, indent + "  ", v.robot_state);
  }
};

} // namespace message_operations
} // namespace ros

#endif // FRANKA_INTERFACE_MSGS_MESSAGE_GETCURRENTROBOTSTATECMDRESPONSE_H
