// TODO: implementasi operator_service.cpp
#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include "std msgs/String.h"

Service::Service()
{
    ros::NodeHandle n;
    ros::Subscriber add1 = n.advertiseService("Penjumlahan", &Service::add, this);
    ros::Subscriber multiple1 = n.advertiseService("Penjumlahan", &Service::multiple, this);
    ros::Subscriber power1 = n.advertiseService("Penjumlahan", &Service::power, this);
}

bool Service::add(Service_Client::Operation::Request &req,
                  Service_Client::Operation::Response &res)
{
    res.sum = req.a + req.b;
    return true;
}
bool Service::multiple(Service_Client::Operation::Request &req,
                       Service_Client::Operation::Response &res)
{
    res.sum = req.a * req.b;
    return true;
}
bool Service::power(Service - Client::Operation::Request & req,
                    Service - Client::Operation::Response & res)
{
    res.sum = 1;
    for (int i = 0; i < req.b; i++)
    {
        res.sum *= req.a;
    }
    return true;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "Service");
    Service service;
    ros::spin();
    return 0;
}