// TODO: implementasi operator_service.cpp

#include "operator_service.hpp"

Service::Service() {

    penjumlahan_serv = nh.advertiseService("Penjumlahan", &Service::penjumlahan, this);

    perkalian_serv = nh.advertiseService("Perkalian", &Service::perkalian, this);

    perpangkatan_serv = nh.advertiseService("Perpangkatan", &Service::perpangkatan, this);

}

bool Service::penjumlahan(service_client::Operation::Request &req,
                          service_client::Operation::Response &res) {

    res.result = req.a + req.b;
                    
    return true; 

}

bool Service::perkalian(service_client::Operation::Request &req,
                        service_client::Operation::Response &res) {

    res.result = req.a * req.b;

    return true;
    
}

bool Service::perpangkatan(service_client::Operation::Request &req,
                           service_client::Operation::Response &res) {

    int temp_result = 1;

    for (int i = 0; i < req.b; i++) {

         temp_result = temp_result * req.a;

    }

    res.result = temp_result;

    return true;

}

int main(int argc, char **argv) {

    ros::init(argc, argv, "serviceNode");

    Service service;

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
// rosrun service_client operator_service_node