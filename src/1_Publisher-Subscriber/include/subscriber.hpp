#ifndef __SUBSCRIBER__
#define __SUBSCRIBER__

#include "ros/ros.h"
#include "std_msgs/String.h"

class Subscriber {
    private:

        ros::NodeHandle nh;

        ros::Subscriber HelloWorld_sub;

    public:

        Subscriber();

        void HelloWorldCallback(const std_msgs::String::ConstPtr& msg);

};

#endif
