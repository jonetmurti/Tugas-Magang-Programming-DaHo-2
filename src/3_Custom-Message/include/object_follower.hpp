#ifndef __OBJECT_FOLLOWER__
#define __OBJECT_FOLLOWER__

#include "ros/ros.h"
#include <math.h>
#include "custom_message/Position.h"
#include "custom_message/Servo.h"

class ObjectFollower {
    private:

        ros::NodeHandle nh;

        ros::Publisher servo_pub;

        ros::Subscriber position_sub;

        custom_message::Position position;

    public:

        ObjectFollower();

        void PositionCallBack(const custom_message::Position::ConstPtr& msg);

        void proses();

};

#endif