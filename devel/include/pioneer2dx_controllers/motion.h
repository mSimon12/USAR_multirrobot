// Generated by gencpp from file pioneer2dx_controllers/motion.msg
// DO NOT EDIT!


#ifndef PIONEER2DX_CONTROLLERS_MESSAGE_MOTION_H
#define PIONEER2DX_CONTROLLERS_MESSAGE_MOTION_H

#include <ros/service_traits.h>


#include <pioneer2dx_controllers/motionRequest.h>
#include <pioneer2dx_controllers/motionResponse.h>


namespace pioneer2dx_controllers
{

struct motion
{

typedef motionRequest Request;
typedef motionResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct motion
} // namespace pioneer2dx_controllers


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::pioneer2dx_controllers::motion > {
  static const char* value()
  {
    return "5f07416156f9cd98c81988e24b4d6bda";
  }

  static const char* value(const ::pioneer2dx_controllers::motion&) { return value(); }
};

template<>
struct DataType< ::pioneer2dx_controllers::motion > {
  static const char* value()
  {
    return "pioneer2dx_controllers/motion";
  }

  static const char* value(const ::pioneer2dx_controllers::motion&) { return value(); }
};


// service_traits::MD5Sum< ::pioneer2dx_controllers::motionRequest> should match
// service_traits::MD5Sum< ::pioneer2dx_controllers::motion >
template<>
struct MD5Sum< ::pioneer2dx_controllers::motionRequest>
{
  static const char* value()
  {
    return MD5Sum< ::pioneer2dx_controllers::motion >::value();
  }
  static const char* value(const ::pioneer2dx_controllers::motionRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::pioneer2dx_controllers::motionRequest> should match
// service_traits::DataType< ::pioneer2dx_controllers::motion >
template<>
struct DataType< ::pioneer2dx_controllers::motionRequest>
{
  static const char* value()
  {
    return DataType< ::pioneer2dx_controllers::motion >::value();
  }
  static const char* value(const ::pioneer2dx_controllers::motionRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::pioneer2dx_controllers::motionResponse> should match
// service_traits::MD5Sum< ::pioneer2dx_controllers::motion >
template<>
struct MD5Sum< ::pioneer2dx_controllers::motionResponse>
{
  static const char* value()
  {
    return MD5Sum< ::pioneer2dx_controllers::motion >::value();
  }
  static const char* value(const ::pioneer2dx_controllers::motionResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::pioneer2dx_controllers::motionResponse> should match
// service_traits::DataType< ::pioneer2dx_controllers::motion >
template<>
struct DataType< ::pioneer2dx_controllers::motionResponse>
{
  static const char* value()
  {
    return DataType< ::pioneer2dx_controllers::motion >::value();
  }
  static const char* value(const ::pioneer2dx_controllers::motionResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // PIONEER2DX_CONTROLLERS_MESSAGE_MOTION_H
