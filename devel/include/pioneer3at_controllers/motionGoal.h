// Generated by gencpp from file pioneer3at_controllers/motionGoal.msg
// DO NOT EDIT!


#ifndef PIONEER3AT_CONTROLLERS_MESSAGE_MOTIONGOAL_H
#define PIONEER3AT_CONTROLLERS_MESSAGE_MOTIONGOAL_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geometry_msgs/Twist.h>

namespace pioneer3at_controllers
{
template <class ContainerAllocator>
struct motionGoal_
{
  typedef motionGoal_<ContainerAllocator> Type;

  motionGoal_()
    : destination()  {
    }
  motionGoal_(const ContainerAllocator& _alloc)
    : destination(_alloc)  {
  (void)_alloc;
    }



   typedef  ::geometry_msgs::Twist_<ContainerAllocator>  _destination_type;
  _destination_type destination;





  typedef boost::shared_ptr< ::pioneer3at_controllers::motionGoal_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::pioneer3at_controllers::motionGoal_<ContainerAllocator> const> ConstPtr;

}; // struct motionGoal_

typedef ::pioneer3at_controllers::motionGoal_<std::allocator<void> > motionGoal;

typedef boost::shared_ptr< ::pioneer3at_controllers::motionGoal > motionGoalPtr;
typedef boost::shared_ptr< ::pioneer3at_controllers::motionGoal const> motionGoalConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::pioneer3at_controllers::motionGoal_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::pioneer3at_controllers::motionGoal_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::pioneer3at_controllers::motionGoal_<ContainerAllocator1> & lhs, const ::pioneer3at_controllers::motionGoal_<ContainerAllocator2> & rhs)
{
  return lhs.destination == rhs.destination;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::pioneer3at_controllers::motionGoal_<ContainerAllocator1> & lhs, const ::pioneer3at_controllers::motionGoal_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace pioneer3at_controllers

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::pioneer3at_controllers::motionGoal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::pioneer3at_controllers::motionGoal_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::pioneer3at_controllers::motionGoal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::pioneer3at_controllers::motionGoal_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::pioneer3at_controllers::motionGoal_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::pioneer3at_controllers::motionGoal_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::pioneer3at_controllers::motionGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "0ee7a53442725ed49843ff163a1b1b2a";
  }

  static const char* value(const ::pioneer3at_controllers::motionGoal_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x0ee7a53442725ed4ULL;
  static const uint64_t static_value2 = 0x9843ff163a1b1b2aULL;
};

template<class ContainerAllocator>
struct DataType< ::pioneer3at_controllers::motionGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "pioneer3at_controllers/motionGoal";
  }

  static const char* value(const ::pioneer3at_controllers::motionGoal_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::pioneer3at_controllers::motionGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n"
"#Define the goal\n"
"geometry_msgs/Twist destination\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Twist\n"
"# This expresses velocity in free space broken into its linear and angular parts.\n"
"Vector3  linear\n"
"Vector3  angular\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Vector3\n"
"# This represents a vector in free space. \n"
"# It is only meant to represent a direction. Therefore, it does not\n"
"# make sense to apply a translation to it (e.g., when applying a \n"
"# generic rigid transformation to a Vector3, tf2 will only apply the\n"
"# rotation). If you want your data to be translatable too, use the\n"
"# geometry_msgs/Point message instead.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
;
  }

  static const char* value(const ::pioneer3at_controllers::motionGoal_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::pioneer3at_controllers::motionGoal_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.destination);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct motionGoal_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::pioneer3at_controllers::motionGoal_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::pioneer3at_controllers::motionGoal_<ContainerAllocator>& v)
  {
    s << indent << "destination: ";
    s << std::endl;
    Printer< ::geometry_msgs::Twist_<ContainerAllocator> >::stream(s, indent + "  ", v.destination);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PIONEER3AT_CONTROLLERS_MESSAGE_MOTIONGOAL_H
