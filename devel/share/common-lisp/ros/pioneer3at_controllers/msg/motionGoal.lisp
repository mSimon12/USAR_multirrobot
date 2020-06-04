; Auto-generated. Do not edit!


(cl:in-package pioneer3at_controllers-msg)


;//! \htmlinclude motionGoal.msg.html

(cl:defclass <motionGoal> (roslisp-msg-protocol:ros-message)
  ((destination
    :reader destination
    :initarg :destination
    :type geometry_msgs-msg:Twist
    :initform (cl:make-instance 'geometry_msgs-msg:Twist)))
)

(cl:defclass motionGoal (<motionGoal>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <motionGoal>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'motionGoal)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name pioneer3at_controllers-msg:<motionGoal> is deprecated: use pioneer3at_controllers-msg:motionGoal instead.")))

(cl:ensure-generic-function 'destination-val :lambda-list '(m))
(cl:defmethod destination-val ((m <motionGoal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pioneer3at_controllers-msg:destination-val is deprecated.  Use pioneer3at_controllers-msg:destination instead.")
  (destination m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <motionGoal>) ostream)
  "Serializes a message object of type '<motionGoal>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'destination) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <motionGoal>) istream)
  "Deserializes a message object of type '<motionGoal>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'destination) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<motionGoal>)))
  "Returns string type for a message object of type '<motionGoal>"
  "pioneer3at_controllers/motionGoal")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'motionGoal)))
  "Returns string type for a message object of type 'motionGoal"
  "pioneer3at_controllers/motionGoal")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<motionGoal>)))
  "Returns md5sum for a message object of type '<motionGoal>"
  "0ee7a53442725ed49843ff163a1b1b2a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'motionGoal)))
  "Returns md5sum for a message object of type 'motionGoal"
  "0ee7a53442725ed49843ff163a1b1b2a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<motionGoal>)))
  "Returns full string definition for message of type '<motionGoal>"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%#Define the goal~%geometry_msgs/Twist destination~%~%================================================================================~%MSG: geometry_msgs/Twist~%# This expresses velocity in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'motionGoal)))
  "Returns full string definition for message of type 'motionGoal"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%#Define the goal~%geometry_msgs/Twist destination~%~%================================================================================~%MSG: geometry_msgs/Twist~%# This expresses velocity in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <motionGoal>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'destination))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <motionGoal>))
  "Converts a ROS message object to a list"
  (cl:list 'motionGoal
    (cl:cons ':destination (destination msg))
))
