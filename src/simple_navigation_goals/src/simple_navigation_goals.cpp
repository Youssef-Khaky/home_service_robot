#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <geometry_msgs/Pose.h>
#include <actionlib/client/simple_action_client.h>
// #include <simple_navigation_goals/pose_str.h> WHY IS THIS NOT WORKING!!
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv){
  ros::init(argc, argv, "simple_navigation_goals");
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<geometry_msgs::Pose>("goal_pose", 0);
  geometry_msgs::Pose pose;

  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

  //wait for the action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  move_base_msgs::MoveBaseGoal goal;


  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();



  goal.target_pose.pose.position.x = 3.7081;
  goal.target_pose.pose.position.y = 0.2838;
  goal.target_pose.pose.orientation.w = 1.0;

  ROS_INFO("Sending goal");
  ac.sendGoal(goal);
  ROS_INFO("waiting for result");
  ac.waitForResult();
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
    pose.position.x = goal.target_pose.pose.position.x;
    pose.position.y = goal.target_pose.pose.position.y;
    pose.position.z = 1; //1 means picked, at least for now will the include for custom msgs gets fixed
    // pose.pose.status = "picked";
    chatter_pub.publish(pose);
    ROS_INFO("Hooray, the base moved 1 meter forward");
  } else {
    ROS_INFO("The base failed to move forward 1 meter for some reason");
  }
  ROS_INFO("picked up!!");

  ROS_INFO("nap time");
  ros::Duration(5).sleep();

  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();
  ROS_INFO("good morning");

  goal.target_pose.pose.position.x = 3.4634;
  goal.target_pose.pose.position.y = -8.5;
  goal.target_pose.pose.orientation.w = 1.0;
  ROS_INFO("Sending the second goal");
  ac.sendGoal(goal);
  ROS_INFO("waiting for result");
  ac.waitForResult();
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
    pose.position.x = goal.target_pose.pose.position.x;
    pose.position.y = goal.target_pose.pose.position.y;
    pose.position.z = 2; //2 means dropped, at least for now will the include for custom msgs gets fixed
    // pose.pose.status = "picked";
    chatter_pub.publish(pose);
    // pose.pose.x = goal.target_pose.pose.position.x;
    // pose.pose.y = goal.target_pose.pose.position.y
    // pose.pose.status = "dropped"
    // chatter_pub.publish(pose);

    ROS_INFO("Hooray, the base moved 1 meter forward");
  } else {ROS_INFO("The base failed to move forward 1 meter for some reason");
}
  ROS_INFO("dropped off!");

  // if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
  //   ROS_INFO("Hooray, the base moved 1 meter forward");
  // else
  //   ROS_INFO("The base failed to move forward 1 meter for some reason");

  return 0;
}
