#ifndef __SERVO_CONTROLLER__
#define __SERVO_CONTROLLER__

#include "ros/ros.h"
#include "custom_message/Servo.h"

class ServoController {
    private:

        ros::NodeHandle nh;

        ros::Subscriber servo_sub;

    public:

        ServoController();

        void ServoCallback(const custom_message::Servo::ConstPtr& msg);

};

#endif