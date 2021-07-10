#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <iostream>

using namespace std;

class NumberSubscriber {
    private:
        ros::NodeHandle n;
        ros::Subscriber sub;
        int counter;

    public:
        NumberSubscriber() {
            counter = 0;
            sub = n.subscribe<std_msgs::Int32>("chatter", 1000, &NumberSubscriber::chatterCallback, this);
        }
    
        void chatterCallback(const std_msgs::Int32::ConstPtr& msg) {
            counter += msg->data;
        }

        void print() {
            cout << "counter: " << counter << endl;
        }

};

int main(int argc, char **argv) {

    ros::init(argc, argv, "subscriber");

    NumberSubscriber ns;

    ROS_INFO("subscriber running...");

    ros::Rate rate(60);

    while(ros::ok()) {
        ns.print();
        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}