// TODO: implementasi object_follower.cpp

const double VIEW_V_ANGLE = 43.3;  //degree = 0.8028 rad
const double VIEW_H_ANGLE = 70.42;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

#include "object_follower.hpp"

ObjectFollower::ObjectFollower() {

    servo_pub = nh.advertise<custom_message::Servo>("servo_topic", 10);

    position_sub = nh.subscribe("position_topic", 1, &ObjectFollower::PositionCallBack, this);

}

void ObjectFollower::PositionCallBack(const custom_message::Position::ConstPtr& msg) {

    this->position.x = msg->x;
    this->position.y = msg->y;

}

void ObjectFollower::proses() {

    custom_message::Servo temp;

    temp.pitch = -1 * VIEW_H_ANGLE * (this->position.x / SCREEN_WIDTH) / 0.088;
    temp.yaw = -1 * VIEW_V_ANGLE * (this->position.y / SCREEN_HEIGHT) / 0.088;

    this->servo_pub.publish(temp);

}

int main(int argc, char **argv) {

    ros::init(argc, argv, "object_follower_node");

    ObjectFollower of;

    ros::Rate loop_rate(60);

    while (ros::ok()) {   

        of.proses();

        ros::spinOnce();

        loop_rate.sleep();

    }

    return 0;
    
}

// DOKUMENTASI
// Buka terminal baru, lalu masuk directory:
// cd <directory>
// Compile:
// catkin_make
// source devel/setup.bash
// Menjalankan program:
// rosrun custom_message object_follower_node 