// TODO: implementasi subscriber.cpp
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream>

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO(msg->data.c_str());
}


int main(int argc, char **argv) {

    ros::init(argc, argv, "subscriber");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("tugas1", 1000, chatterCallback);
    ros::Rate rate(60);
    ros::spin();
    return 0;
}