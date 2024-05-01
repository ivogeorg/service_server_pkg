// Import header generated for custom message
#include "my_custom_srv_msg_pkg/MyCustomServiceMessage.h"

#include "ros/duration.h"
#include "ros/node_handle.h"
#include "ros/publisher.h"
#include "ros/ros.h"

// Import the generated /cmd_vel topic Twist message header
#include "geometry_msgs/Twist.h"

ros::Publisher vel_pub;
geometry_msgs::Twist vel_cmd;

// We define the callback function of the service
bool my_callback(my_custom_srv_msg_pkg::MyCustomServiceMessage::Request &req,
                 my_custom_srv_msg_pkg::MyCustomServiceMessage::Response &res) {
  // res.some_variable = req.some_variable + req.other_variable;

  // Empty response
  // Send Twist message to /cmd_vel to move BB8 in circle
  vel_cmd.linear.x = 0.25;
  vel_cmd.angular.z = 0.25;
  vel_pub.publish(vel_cmd);

  ros::Duration(req.duration).sleep(); // sleep for req.duration SECONDS

  // Stop robot (might continue due to inertia)
  vel_cmd.linear.x = 0.0;
  vel_cmd.angular.z = 0.0;
  vel_pub.publish(vel_cmd);

  res.success = true;

  ROS_INFO("Service to custom move BB8 for %d seconds: FINISHED", req.duration);

  return true;
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "bb8_move_custom_service_server");
  ros::NodeHandle nh;

  // create the Service /move_bb8_in_circle
  // with the defined callback
  ros::ServiceServer my_service =
      nh.advertiseService("/move_bb8_custom", my_callback);

  // this node is also a publisher
  // to /cmd_vel to make BB8 move
  // in a circle
  vel_pub = nh.advertise<geometry_msgs::Twist>("cmd_vel", 100);

  ROS_INFO("Service to custom move BB8: READY");
  ros::spin(); // mantain the service open.

  return 0;
}