// TODO: implementasi operator_service.cpp
#include "ros/ros.h"
#include "service_client/Operation.h"

bool add(service_client::Operation::Request  &req,
         service_client::Operation::Response &res)
{
    res.result = req.a + req.b;

    return true;
}

bool multi(service_client::Operation::Request  &req,
         service_client::Operation::Response &res)
{
    res.result = req.a * req.b;

    return true;
}

bool power(service_client::Operation::Request  &req,
         service_client::Operation::Response &res)
{   
    int temp = 1;
    for(int i = 1; i < req.b+1; i++){
        temp = temp * req.a;
    }
    res.result = temp;
    return true;
}

int main(int argc, char **argv) {

    ros::init(argc, argv, "server");

    ros::NodeHandle nh;

    ros::ServiceServer serviceadd = nh.advertiseService("add_int", add);
    ros::ServiceServer servicemulti = nh.advertiseService("multi_int", multi);
    ros::ServiceServer servicepower = nh.advertiseService("power_int", power);

    ros::spin();

    return 0;
}