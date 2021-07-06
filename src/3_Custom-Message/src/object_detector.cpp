// TODO: implementasi object_detector.cpp
#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include "std msgs/String.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "object detector");

    ros::NodeHandle n;

    ros::Publisher position_pub = n.advertise<custom_message::Position>("position", 1000);

    ros::Rate loop_rate(60);

    position.x = 640;
    position.y = 480;

    while (ros::ok())
    {
        std_msgs::String msg;
        std::stringstream ss;
        ss << "hello world ";
        msg.data = ss.str();
        ROS_INFO("%s", msg.data.c_str());

        position_pub.publish(positon);
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;