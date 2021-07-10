#include "ros/ros.h"
#include "service_client/Operation.h"



int main(int argc, char **argv) {

    ros::init(argc, argv, "client");

    ros::NodeHandle nh;

    ros::ServiceClient add_client = nh.serviceClient<service_client::Operation>("add_int");
    ros::ServiceClient multi_client = nh.serviceClient<service_client::Operation>("multi_int");
    ros::ServiceClient power_client = nh.serviceClient<service_client::Operation>("power_int");

    int hasil = 0;

    for (int i = 0; i < argc - 2; i++) {

        service_client::Operation srvJumlah, srvKali, srvPangkat;

        srvPangkat.request.a = atoi(argv[1]);
        srvPangkat.request.b = argc - 3 - i;

        power_client.call(srvPangkat);

        srvKali.request.a = atoi(argv[i + 2]);
        srvKali.request.b = (int)srvPangkat.response.result;

      
        multi_client.call(srvKali);

        srvJumlah.request.a = hasil;
        srvJumlah.request.b = (int)srvKali.response.result;

        add_client.call(srvJumlah);

        hasil = (int)srvJumlah.response.result;
    }
    ROS_INFO("%d",hasil);
    return 0;
}