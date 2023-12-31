// Generated by gencpp from file franka_interface_msgs/SensorData.msg
// DO NOT EDIT!


#ifndef FRANKA_INTERFACE_MSGS_MESSAGE_SENSORDATA_H
#define FRANKA_INTERFACE_MSGS_MESSAGE_SENSORDATA_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace franka_interface_msgs
{
template <class ContainerAllocator>
struct SensorData_
{
  typedef SensorData_<ContainerAllocator> Type;

  SensorData_()
    : header()
    , info()
    , type(0)
    , size(0)
    , sensorData()  {
    }
  SensorData_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , info(_alloc)
    , type(0)
    , size(0)
    , sensorData(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _info_type;
  _info_type info;

   typedef uint8_t _type_type;
  _type_type type;

   typedef int32_t _size_type;
  _size_type size;

   typedef std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>> _sensorData_type;
  _sensorData_type sensorData;





  typedef boost::shared_ptr< ::franka_interface_msgs::SensorData_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::franka_interface_msgs::SensorData_<ContainerAllocator> const> ConstPtr;

}; // struct SensorData_

typedef ::franka_interface_msgs::SensorData_<std::allocator<void> > SensorData;

typedef boost::shared_ptr< ::franka_interface_msgs::SensorData > SensorDataPtr;
typedef boost::shared_ptr< ::franka_interface_msgs::SensorData const> SensorDataConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::franka_interface_msgs::SensorData_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::franka_interface_msgs::SensorData_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::franka_interface_msgs::SensorData_<ContainerAllocator1> & lhs, const ::franka_interface_msgs::SensorData_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.info == rhs.info &&
    lhs.type == rhs.type &&
    lhs.size == rhs.size &&
    lhs.sensorData == rhs.sensorData;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::franka_interface_msgs::SensorData_<ContainerAllocator1> & lhs, const ::franka_interface_msgs::SensorData_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace franka_interface_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::franka_interface_msgs::SensorData_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::franka_interface_msgs::SensorData_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::franka_interface_msgs::SensorData_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::franka_interface_msgs::SensorData_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::franka_interface_msgs::SensorData_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::franka_interface_msgs::SensorData_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::franka_interface_msgs::SensorData_<ContainerAllocator> >
{
  static const char* value()
  {
    return "aaefdf50e303c513cc9b7bfed30bdd94";
  }

  static const char* value(const ::franka_interface_msgs::SensorData_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xaaefdf50e303c513ULL;
  static const uint64_t static_value2 = 0xcc9b7bfed30bdd94ULL;
};

template<class ContainerAllocator>
struct DataType< ::franka_interface_msgs::SensorData_<ContainerAllocator> >
{
  static const char* value()
  {
    return "franka_interface_msgs/SensorData";
  }

  static const char* value(const ::franka_interface_msgs::SensorData_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::franka_interface_msgs::SensorData_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Sensor data\n"
"std_msgs/Header header\n"
"string info\n"
"uint8 type\n"
"int32 size\n"
"uint8[] sensorData\n"
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
;
  }

  static const char* value(const ::franka_interface_msgs::SensorData_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::franka_interface_msgs::SensorData_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.info);
      stream.next(m.type);
      stream.next(m.size);
      stream.next(m.sensorData);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SensorData_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::franka_interface_msgs::SensorData_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::franka_interface_msgs::SensorData_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "info: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.info);
    s << indent << "type: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.type);
    s << indent << "size: ";
    Printer<int32_t>::stream(s, indent + "  ", v.size);
    s << indent << "sensorData[]" << std::endl;
    for (size_t i = 0; i < v.sensorData.size(); ++i)
    {
      s << indent << "  sensorData[" << i << "]: ";
      Printer<uint8_t>::stream(s, indent + "  ", v.sensorData[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // FRANKA_INTERFACE_MSGS_MESSAGE_SENSORDATA_H
