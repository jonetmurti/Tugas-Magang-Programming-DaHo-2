#include "ros/ros.h"
#include "std_msgs/String.h"


void writeMsgTolog(const std_msgs::String::constPtr& msg){
    ROS_INFO("The message that we received was: %s", msg->data.c_str());
}

int main(int argc, char **argv) {

    ros::init(argc, argv, "subscriber");

    ros::NodeHandle nh;

    ros::Subscriber topic_sub = nh.subscribe("subscribe", 1000, writeMsgTolog);
    
    ros::spin();


    return 0;
}
