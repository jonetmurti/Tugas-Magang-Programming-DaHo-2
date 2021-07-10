#include "ros/ros.h"
#include "std_msgs/String.h"

void print(const std_msg::String::ConstPtr& msg){
    ROS_INFO("Topic yang diambil :",msg->data.c_str());
}

int main(int argc, char **argv){
    ros::init(argc,argv,"Subcriber_node");
    ros::NodeHandle nh;
    ros::Subcriber topic_pub = nh.subscribe<std_msgs::String>("Testing",50, print)

    ros::spin();
    return 0;
}