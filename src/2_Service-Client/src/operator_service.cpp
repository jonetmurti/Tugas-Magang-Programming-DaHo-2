#include "ros/ros.h"
#include "intro/arithmetic.h"

bool add(intro::arithmetic::Request  &req,
         intro::arithmetic::Response &res)
{
    res.result = req.a + req.b;

    return true;
}

int main(int argc, char **argv) {

    ros::init(argc, argv, "server");

    ros::NodeHandle n;

    ros::ServiceServer service = n.advertiseService("add_int", add);

    ROS_INFO("server running...");

    ros::spin();

    return 0;
}