### `service_server_pkg`

#### 1. [`simple_service_server`](src/simple_service_server.cpp)

`roslaunch service_server_pkg service_server.launch`

1. Service with no arguments, no messages (`std_srvs/Empty`)
2. Server prints to `stdout` when called, client receives an empty message.

#### 2. [`bb8_move_in_circle_service_server`](src/bb8_move_in_circle_service_server.cpp)

1. Empty message service.
2. Publishes `geometry_msgs::Twist` messages to `/cmd_vel` to move the BB8 robot in a circle.

`roslaunch service_server_pkg start_bb8_move_in_circle_service_server.launch`

#### 3. [`bb8_move_in_circle_service_client`](src/bb8_move_in_circle_service_client.cpp)

1. Sends empty message to the server above.
2. The server needs to be started to provide the service.

`roslaunch service_server_pkg call_bb8_move_in_circle_service_server.launch`

#### 4. Custom message `MyCustomServiceMessage.srv`

1. Custom message defined in [`my_custom_srv_msg_pkg`](https://github.com/ivogeorg/my_custom_srv_msg_pkg.git).
2. Contains request and response.
3. Infrastructure code generated upon compilation of the package. Can be used by other packages. See below.

#### 5. [`bb8_move_custom_service_server`](src/bb8_move_custom_service_server.cpp)

1. Service using the custom message above. The request contains a duration (in sec) to keep the robot moving. Uses `ros::Duration(_num_secs_).sleep()`.
2. Publishes `geometry_msgs::Twist` messages to `/cmd_vel` to move the BB8 robot in a circle. At the end of the duration, the robot is stopped.

`roslaunch service_server_pkg start_bb8_move_custom_service_server.launch`


#### 6. [`bb8_move_custom_service_client`](src/bb8_move_custom_service_client.cpp)

1. Sends custom message to the server above.
2. The server needs to be started to provide the service.
3. The server sends `success=true` upon completion of the `msg.request.duration` bound motion in circle of the robot.

`roslaunch service_server_pkg call_bb8_move_custom_service_server.launch`

