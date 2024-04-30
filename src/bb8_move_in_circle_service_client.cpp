#include "ros/ros.h"
#include "std_srvs/Empty.h"

int main(int argc, char **argv) {
  // Initialise a ROS node with the name service_client
  //   ros::init(argc, argv, "service_client");
  ros::init(argc, argv, "bb8_move_in_circle_service_client");
  ros::NodeHandle nh;

  // Create the connection to the service /trajectory_by_name

  // wait for service to be running
  ros::service::waitForService("/move_bb8_in_circle");

  ros::ServiceClient call_move_bb8_in_circle_service =
      nh.serviceClient<std_srvs::Empty>(
          "/move_bb8_in_circle");

    std_srvs::Empty empty_msg;

  // Send through the connection the name of the trajectory to execute
  if (call_move_bb8_in_circle_service.call(empty_msg)) {
    // Print the result given by the service called
    ROS_INFO("Successfully called service /move_bb8_in_circle");
  } else {
    ROS_ERROR("Failed to call service /move_bb8_in_circle");
    return 1;
  }

  return 0;
}