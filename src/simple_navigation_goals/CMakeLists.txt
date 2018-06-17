cmake_minimum_required(VERSION 2.8.3)
project(simple_navigation_goals)


find_package(catkin REQUIRED COMPONENTS  actionlib  move_base_msgs	custom_pose_msg  roscpp	genmsg message_generation geometry_msgs)

add_message_files(FILES pose_str.msg)

generate_messages(DEPENDENCIES std_msgs geometry_msgs)



catkin_package(CATKIN_DEPENDS message_runtime)

include_directories(  ${catkin_INCLUDE_DIRS})

add_executable(${PROJECT_NAME}_node src/simple_navigation_goals.cpp)
# add_dependencies(simple_navigation_goals_node ${catkin_EXPORTED_TARGETS})


add_dependencies(${PROJECT_NAME}_node ${PROJECT_NAME}_generate_messages_cpp)
# add_dependencies(${PROJECT_NAME}_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(${PROJECT_NAME}_node  ${catkin_LIBRARIES})
