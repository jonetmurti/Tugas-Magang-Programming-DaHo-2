#include "ros/ros.h"
#include "std_msgs/Int32.h"

class NumberPublisher {
    private:
        ros::NodeHandle n;
        ros::Publisher chatter_pub;

    public:
        NumberPublisher() {
            chatter_pub = n.advertise<std_msgs::Int32>("chatter", 1000);
        }

        void process(int data) {
            std_msgs::Int32 msg;

            msg.data = data;

            chatter_pub.publish(msg);
        }
};

int main(int argc, char **argv) {

    ros::init(argc, argv, "publisher");

    NumberPublisher np;

    ROS_INFO("publisher running...");

    ros::Rate loop_rate(60);

    while (ros::ok()) {

        np.process(1);

        loop_rate.sleep();
    }

    return 0;
}