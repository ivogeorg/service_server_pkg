#include "ros/node_handle.h"
#include "ros/publisher.h"
#include "ros/ros.h"
#include "std_srvs/Empty.h"
// Import the service message header file generated from the Empty.srv message
#include "geometry_msgs/Twist.h"
// Import the generated /cmd_vel topic Twist message header

ros::Publisher vel_pub;
geometry_msgs::Twist vel_cmd;

// We define the callback function of the service
bool my_callback(std_srvs::Empty::Request &req,
                 std_srvs::Empty::Response &res) {
  // res.some_variable = req.some_variable + req.other_variable;

  // Empty response
  // Send Twist message to /cmd_vel to move BB8 in circle
  vel_cmd.linear.x = 0.25;
  vel_cmd.angular.z = 0.25;
  vel_pub.publish(vel_cmd);

  ROS_INFO("Service to move BB8 in a circle: FINISHED"); // We print a string
                                                         // whenever the Service
                                                         // gets called
  return true;
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "bb8_move_in_circle_service_server");
  ros::NodeHandle nh;

  // create the Service /move_bb8_in_circle
  // with the defined callback
  ros::ServiceServer my_service =
      nh.advertiseService("/move_bb8_in_circle", my_callback);

  // this node is also a publisher
  // to /cmd_vel to make BB8 move
  // in a circle
  vel_pub = nh.advertise<geometry_msgs::Twist>("cmd_vel", 100);

  ROS_INFO("Service to move BB8 in a cirlce: READY");
  ros::spin(); // mantain the service open.

  return 0;
}