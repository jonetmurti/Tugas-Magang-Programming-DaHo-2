#ifndef __SERVICE__
#define __SERVICE__

#include "ros/ros.h"
#include "service_client/Operation.h"

class Service {
    private:

        ros::NodeHandle nh;

        ros::ServiceServer penjumlahan_serv, perkalian_serv, perpangkatan_serv;

    public:

        Service();

        bool penjumlahan(service_client::Operation::Request &req,
                         service_client::Operation::Response &res);

        bool perkalian(service_client::Operation::Request &req,
                       service_client::Operation::Response &res);

        bool perpangkatan(service_client::Operation::Request &req,
                          service_client::Operation::Response &res);

};

#endif