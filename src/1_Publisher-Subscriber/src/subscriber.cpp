// TODO: implementasi subscriber.cpp

#include "subscriber.hpp"

Subscriber::Subscriber() {

    HelloWorld_sub = nh.subscribe("topicHelloWorld", 1, &Subscriber::HelloWorldCallback, this);

}

void Subscriber::HelloWorldCallback(const std_msgs::String::ConstPtr& msg){

    ROS_INFO(msg->data.c_str());

}

int main(int argc, char **argv){

    ros::init(argc, argv, "nodeSubscriberHelloWorld");

    Subscriber sub;

    ros::spin();

    return 0;
    
}

// DOKUMENTASI
// Buka terminal baru, lalu masuk directory:
// cd <directory>
// Compile:
// catkin_make
// source devel/setup.bash
// Menjalankan program:
// rosrun publisher_subscriber subscriber_node
// [ INFO] [1625549577.431270931]: Hello, World!
// [ INFO] [1625549577.447847465]: Hello, World!
// [ INFO] [1625549577.464559993]: Hello, World!
// [ INFO] [1625549577.481168625]: Hello, World!
// [ INFO] [1625549577.497950812]: Hello, World!
// [ INFO] [1625549577.514505510]: Hello, World!
// ...
