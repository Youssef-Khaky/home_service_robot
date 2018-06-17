#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <geometry_msgs/Pose.h>
#include <iostream>
using namespace std;

// class mkr{
//
// }
// visualization_msgs::Marker marker;
// ros::NodeHandle n;
// ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 0,true);

// Function declarations
// void ComPoseCallback(const geometry_msgs::Pose::ConstPtr& msg);
void ComPoseCallback(const geometry_msgs::Pose::ConstPtr& msg)
{
  // if {}//if z = 0 , delete,else if z = 1, put
  //is there a way i font have to define all this stuff again?

  ros::NodeHandle n;
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 0,true);
  visualization_msgs::Marker marker;
  marker.header.frame_id = "/map";
  marker.header.stamp = ros::Time::now();
  marker.ns = "basic_shapes";
  marker.id = 0;
  if (msg->position.z == 1){
    marker.action = visualization_msgs::Marker::DELETE;
    ROS_INFO("picked up objectttt");
    marker_pub.publish(marker);
  }else if ( msg->position.z == 2 ){
    uint32_t shape = visualization_msgs::Marker::CUBE;
    marker.type = shape;
    marker.action = visualization_msgs::Marker::ADD;
    marker.pose.position.x = msg->position.x;
    marker.pose.position.y = msg->position.y;
    marker.pose.position.z = 0;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;
    marker.scale.x = 1.0;
    marker.scale.y = 1.0;
    marker.scale.z = 1.0;
    marker.color.r = 1.0f;
    marker.color.g = 1.0f;
    marker.color.b = 0.0f;
    marker.color.a = 1.0;
    marker.lifetime = ros::Duration();
    ros::Duration(1).sleep();
    ROS_INFO("dropped off");
    marker_pub.publish(marker);

  }

  // ROS_INFO("I heard: [%f]", msg->position.x);
  // ROS_INFO("I heard: [%f]", msg->position.y);
  // ROS_INFO("I heard: [%f]", msg->position.z);
  return;
}


int main( int argc, char** argv )
{
  ros::init(argc, argv, "listener");
  ros::NodeHandle n;
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 0,true);
  // ros::NodeHandle n;
  // ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 0,true);
  ros::Subscriber sub = n.subscribe("goal_pose", 0, ComPoseCallback);

  uint32_t shape = visualization_msgs::Marker::CUBE;
  visualization_msgs::Marker marker;
  marker.header.frame_id = "/map";
  marker.header.stamp = ros::Time::now();
  marker.ns = "basic_shapes";
  marker.id = 0;
  marker.type = shape;
  marker.action = visualization_msgs::Marker::ADD;
  marker.pose.position.x = 3.7081;
  marker.pose.position.y = 0.2838;
  marker.pose.position.z = 0;
  marker.pose.orientation.x = 0.0;
  marker.pose.orientation.y = 0.0;
  marker.pose.orientation.z = 0.0;
  marker.pose.orientation.w = 1.0;
  marker.scale.x = 1.0;
  marker.scale.y = 1.0;
  marker.scale.z = 1.0;
  marker.color.r = 1.0f;
  marker.color.g = 1.0f;
  marker.color.b = 0.0f;
  marker.color.a = 1.0;
  marker.lifetime = ros::Duration();
  ros::Duration(1).sleep();
  ROS_INFO("PUBLISHED");
  marker_pub.publish(marker);
  ROS_INFO("going to location");
  // ros::Duration(5).sleep();
  // marker.action = visualization_msgs::Marker::DELETE;
  // ROS_INFO("picked up object");
  // marker_pub.publish(marker);
  // ros::Duration(5).sleep();
  // ROS_INFO("delivered object");
  // marker.action = visualization_msgs::Marker::ADD;
  // marker.pose.position.x = 3.4634;
  // marker.pose.position.y = -8.5;
  // // ros::Duration(1).sleep();
  // marker_pub.publish(marker);
  ros::spin();

  return 0;
}









//
//
// #include <ros/ros.h>
// #include <visualization_msgs/Marker.h>
//
// int main( int argc, char** argv )
// {
//   ros::init(argc, argv, "basic_shapes");
//   ros::NodeHandle n;
//   // ros::Rate r(1);
//   // ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("VM", 0);
//   ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 0);
//
//
//   visualization_msgs::Marker sp;
//   ros::Duration(1).sleep();
//
//   sp.header.frame_id = "map";
//   sp.header.stamp = ros::Time();
//   sp.ns = "my_namespace";
//   sp.id = 0;
//   sp.type = visualization_msgs::Marker::SPHERE;
//   sp.action = visualization_msgs::Marker::ADD;
//   sp.pose.position.x = 0;
//   sp.pose.position.y = 0;
//   sp.pose.position.z = 0;
//   sp.pose.orientation.x = 0.0;
//   sp.pose.orientation.y = 0.0;
//   sp.pose.orientation.z = 0.0;
//   sp.pose.orientation.w = 1.0;
//   sp.scale.x = 1;
//   sp.scale.y = 1;
//   sp.scale.z = 1;
//   sp.color.a = 1.0; // Don't forget to set the alpha!
//   sp.color.r = 0.0;
//   sp.color.g = 1.0;
//   sp.color.b = 0.0;
//   sp.lifetime = ros::Duration();
//   ROS_INFO("published first marker");
//   //only if using a MESH_RESOURCE marker type:
//   // marker.mesh_resource = "package://pr2_description/meshes/base_v0/base.dae";
//   marker_pub.publish( sp );
//   ros::Duration(1).sleep();
//
//   // marker.action = visualization_msgs::Marker::DELETEALL;
//   // marker_pub.publish(marker);
//   // ROS_INFO("Deleted all pre-existing markers");
//   marker.header.frame_id = "map";
//   marker.header.stamp = ros::Time::now();
//   marker.ns = "basic_shapes";
//   marker.id = 0;
//   marker.type = shape;
//   marker.action = visualization_msgs::Marker::ADD;
//
//   marker.pose.position.x = 3.7081;
//   marker.pose.position.y = 0.2838;
//   marker.pose.position.z = 0;
//   marker.pose.orientation.x = 0.0;
//   marker.pose.orientation.y = 0.0;
//   marker.pose.orientation.z = 0.0;
//   marker.pose.orientation.w = 1.0;
//
//   marker.scale.x = 1.0;
//   marker.scale.y = 1.0;
//   marker.scale.z = 1.0;
//
//   marker.color.r = 0.0f;
//   marker.color.g = 1.0f;
//   marker.color.b = 0.0f;
//   marker.color.a = 1.0;
//
//
//   // marker.lifetime = ros::Duration();
//   ROS_INFO("published first marker");
//   marker_pub.publish(marker);
//
//   ros::Duration(1).sleep();
//
//   marker.action = visualization_msgs::Marker::DELETE;
//   ROS_INFO("deleted first marker");
//
//   marker_pub.publish(marker);
//   ROS_INFO("waiting 5 secs");
//   ros::Duration(1).sleep();
//   marker.header.frame_id = "map";
//   marker.header.stamp = ros::Time::now();
//   marker.ns = "basic_shapes";
//   marker.id = 0;
//   marker.type = shape;
//
//   marker.pose.position.x = 3.4634;
//   marker.pose.position.y = -8.5;
//   marker.pose.position.z = 0;
//   marker.pose.orientation.x = 0.0;
//   marker.pose.orientation.y = 0.0;
//   marker.pose.orientation.z = 0.0;
//   marker.pose.orientation.w = 1.0;
//
//   marker.scale.x = 1.0;
//   marker.scale.y = 1.0;
//   marker.scale.z = 1.0;
//
//   marker.color.r = 0.0f;
//   marker.color.g = 1.0f;
//   marker.color.b = 0.0f;
//   marker.color.a = 1.0;
//   marker.action = visualization_msgs::Marker::ADD;
//   // marker.lifetime = ros::Duration();
//   ROS_INFO("published at new location");
//   marker_pub.publish(marker);
//   ros::Duration(1).sleep();
//   marker.action = visualization_msgs::Marker::DELETEALL;
//   marker_pub.publish(marker);
//   ROS_INFO("Deleted all markers");
//   ROS_INFO("waiting 5 secs");
//   ros::Duration(1).sleep();
// }
