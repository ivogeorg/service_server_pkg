#include "my_custom_srv_msg_pkg/MyCustomServiceMessage.h"
#include "ros/ros.h"

int main(int argc, char **argv) {
  // Initialise a ROS node with the name service_client
  //   ros::init(argc, argv, "service_client");
  ros::init(argc, argv, "bb8_move_custom_service_client");
  ros::NodeHandle nh;

  // Create the connection to the service /trajectory_by_name

  // wait for service to be running
  ros::service::waitForService("/move_bb8_custom");

  ros::ServiceClient call_move_bb8_custom_service =
      nh.serviceClient<my_custom_srv_msg_pkg::MyCustomServiceMessage>(
          "/move_bb8_custom");

  my_custom_srv_msg_pkg::MyCustomServiceMessage msg;

  msg.request.duration = 40; // TOIMPROVE: read an argument

  // Send through the connection the name of the trajectory to execute
  if (call_move_bb8_custom_service.call(msg)) {
    // Print the result given by the service called
    ROS_INFO("Successfully called service /move_bb8_custom");
  } else {
    ROS_ERROR("Failed to call service /move_bb8_custom");
    return 1;
  }

  return 0;
}