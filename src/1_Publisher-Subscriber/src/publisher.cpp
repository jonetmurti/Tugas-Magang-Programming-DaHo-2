// TODO: implementasi publisher.cpp
#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char **argv){
    ros::init(argc, argv, "Publisher");
    ros::NodeHandle nh;

    ros::Publisher topic_pub = nh.advertise<std_msgs::String>("tugas1", 1000);
    ros::Rate loop_rate(60);

    while(ros::ok()){
        std_msgs::String msg;
        msg.data = "Hello World!";

        topic_pub.publish(msg);
    }
    return 0;
}