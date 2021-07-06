// TODO: implementasi publisher.cpp

#include "publisher.hpp"

Publisher::Publisher() {

    HelloWorld_pub = nh.advertise<std_msgs::String>("topicHelloWorld", 10);

}

void Publisher::proses() {

    std_msgs::String msg;

    msg.data = "Hello, World!";

    this->HelloWorld_pub.publish(msg);

}

int main(int argc, char **argv) {

    ros::init(argc, argv, "nodePublisherHelloWorld");

    Publisher pub;

    ros::Rate loop_rate(60);

    while (ros::ok()) {   

        pub.proses();     

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
// rosrun publisher_subscriber publisher_node