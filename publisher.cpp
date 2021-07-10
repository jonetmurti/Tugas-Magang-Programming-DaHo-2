#include "ros/ros.h"
#include "std_msgs/String.h"


int main(int argc, char **argv){
    ros::init(argc,argv,"Publisher_node");
    ros::NodeHandle nh;
    ros::Publisher topic_pub = nh.advertise<std_msgs::String>("Testing",50)
    ros::Rate loop_rate(60);

    while(ros::ok()){
        std_msgs::String msg;
        msg.data = "Hello, World!!!";
        topic_pun.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}