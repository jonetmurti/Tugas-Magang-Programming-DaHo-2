#ifndef __CLIENT__
#define __CLIENT__

#include "ros/ros.h"
#include "service_client/Operation.h"

#include <cstdlib>

class Client {
    private:

        ros::NodeHandle nh;

        ros::ServiceClient penjumlahan_client, perkalian_client, perpangkatan_client;

    public:

        Client();

        int fungsi(int argc, char **argv);

};

#endif