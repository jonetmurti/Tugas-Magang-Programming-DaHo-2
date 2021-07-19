#include "ros/ros.h"
#include "service_client/Operation.h"

int main(int argc, char **argv) {

    ros::init(argc, argv, "client");

    ros::NodeHandle nh;

    ros::ServiceClient add_client = nh.serviceClient<intro::arithmetic>("add_int");

    ROS_INFO("client running...");

    intro::arithmetic srv;

    srv.request.a = 5;
    srv.request.b = 6;

    if (add_client.call(srv)) {

        ROS_INFO("Sum: %ld", (long int)srv.response.result);

    } else {

        ROS_ERROR("Failed to call service add_int");

    }

    return 0;
}
