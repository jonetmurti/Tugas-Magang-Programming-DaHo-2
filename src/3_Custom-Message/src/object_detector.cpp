// TODO: implementasi object_detector.cpp

#include "object_detector.hpp"

ObjectDetector::ObjectDetector() {

    position_pub = nh.advertise<custom_message::Position>("position_topic", 10);

}

void ObjectDetector::proses(int sign, custom_message::Position position) {

    position.x = position.x + 5 * sign;
    position.y = position.y + 5 * sign;
    this->position_pub.publish(position);

}

int main(int argc, char **argv) {

    ros::init(argc, argv, "object_detector_node");

    ObjectDetector od; 

    bool cek = true;

    ros::Time StartTime = ros::Time::now();

    custom_message::Position position;

    position.x = 640;
    position.y = 480;

    ros::Rate loop_rate(60);

    int sign = 1;

    while (ros::ok()) {

        if (((int)(ros::Time::now() - StartTime).toSec() % 10 == 5) && cek) {

            if (sign == 1) {
                sign = -1;
            } else {
                sign = 1;
            }

            cek = false;

        }

        if (((int)(ros::Time::now() - StartTime).toSec() % 10 == 6) && !cek) {

            cek = true;

        }

        od.proses(sign, position);
    
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
// rosrun custom_message object_detector_node 