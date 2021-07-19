#include "ros/ros.h"
#include "service_client/Operation.h"

bool add(intro::arithmetic::Request  &req,
         intro::arithmetic::Response &res)
{
    res.result = req.a + req.b;

    return true;
}

bool time(intro::arithmetic::Request  &req,
         intro::arithmetic::Response &res)
{
    res.result = req.a * req.b;

    return true;
}


int main(int argc, char **argv) {

    ros::init(argc, argv, "server");

    ros::NodeHandle nh;

    ros::ServiceServer serviceadd = nh.advertiseService("add_int", add);
    ros::ServiceServer servicetime = nh.advertiseService("add_int", time);

    ROS_INFO("server running...");

    ros::spin();

    return 0;
}
