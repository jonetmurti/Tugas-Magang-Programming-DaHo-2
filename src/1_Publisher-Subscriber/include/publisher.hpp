#ifndef __PUBLISHER__
#define __PUBLISHER__

#include "ros/ros.h"
#include "std_msgs/String.h"

class Publisher {
    private:

        ros::NodeHandle nh;

        ros::Publisher HelloWorld_pub;

    public:

        Publisher();

        void proses();

};

#endif