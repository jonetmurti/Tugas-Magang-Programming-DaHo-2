#ifndef __OBJECT_DETECTOR__
#define __OBJECT_DETECTOR__

#include "ros/ros.h"
#include "custom_message/Position.h"

class ObjectDetector {
    private:

        ros::NodeHandle nh;

        ros::Publisher position_pub;

    public:

        ObjectDetector();

        void proses(int sign, custom_message::Position position);

};

#endif