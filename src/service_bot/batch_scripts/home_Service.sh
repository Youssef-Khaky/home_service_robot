#!/bin/sh
xterm  -e  " roslaunch turtlebot_gazebo turtlebot_world.launch " &
sleep 5
xterm -e   " roslaunch service_bot amcl.launch" &
sleep 5
xterm  -e  " roslaunch turtlebot_rviz_launchers view_navigation.launch" &
sleep 5
xterm  -e  " rosrun  using_markers pose_receiver_node" &
sleep 2
xterm  -e  " rosrun simple_navigation_goals simple_navigation_goals_node"
