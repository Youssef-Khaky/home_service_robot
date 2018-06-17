cmake_minimum_required(VERSION 2.8.3)
project(using_markers)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  visualization_msgs
  std_msgs
  message_generation
  geometry_msgs
)

add_message_files(
   FILES
   pose_str.msg)



catkin_package(
  CATKIN_DEPENDS roscpp visualization_msgs message_runtime
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(basic_shapes src/basic_shapes.cpp)
add_executable(pose_receiver_node src/pose_receiver.cpp)


target_link_libraries(basic_shapes ${catkin_LIBRARIES})
target_link_libraries(pose_receiver_node ${catkin_LIBRARIES})
