### `service_server_pkg`

#### [`simple_service_server`](src/simple_service_server.cpp)

`roslaunch service_server_pkg service_server.launch`

1. Service with no arguments, no messages (`std_srvs/Empty`)
2. Server prints to `stdout` when called, client receives an empty message.

#### [`bb8_move_in_circle_service_server`](src/bb8_move_in_circle_service_server.cpp)

1. Empty message service.
2. Publishes `geometry_msgs::Twist` messages to `/cmd_vel` to move the BB8 robot in a circle.

`roslaunch service_server_pkg start_bb8_move_in_circle_service_server.launch`

#### [`bb8_move_in_circle_service_client`](src/bb8_move_in_circle_service_client.cpp)

1. Sends empty message to the server above.
2. The server needs to be started to provide the service.

`roslaunch service_server_pkg call_bb8_move_in_circle_service_server.launch`
