// TODO: implementasi subscriber.cpp
#include "ros/ros.h"
#include "std_msgs/String.h"

void writeMsgToLog(const std_msgs::String::ConstPtr& msg) {
    ROS_INFO("%s", msg->data.c_str());
}


int main(int argc, char **argv) {
    ros::init(argc, argv, "subscriber");
    ros::NodeHandle nh;

    ros::Subscriber topic_sub = nh.subscribe("Tutorial", 5, writeMsgToLog);

    ros::spin();

    return 0;
}