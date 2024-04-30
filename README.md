### `service_server_pkg`

#### [`simple_service_server`](src/simple_service_server.cpp)

`roslaunch service_server_pkg service_server.launch`

1. Service with no arguments, no messages (`std_srvs/Empty`)
2. Server prints to `stdout` when called, client receives an empty message.

#### [`bb8_move_in_circle_service_server`](src/bb8_move_in_circle_service_server.cpp)

1. Empty message service.
2. Publishes `geometry_msgs::Twist` messages to `/cmd_vel` to move the BB8 robot in a circle.

`roslaunch service_server_pkg start_bb8_move_in_circle_service_server.launch`
