// TODO: implementasi operator_client.cpp

#include "operator_client.hpp"

Client::Client() {

    penjumlahan_client = nh.serviceClient<service_client::Operation>("Penjumlahan");
    
    perkalian_client = nh.serviceClient<service_client::Operation>("Perkalian");
    
    perpangkatan_client = nh.serviceClient<service_client::Operation>("Perpangkatan");

}

int Client::fungsi(int argc, char **argv) {

    int hasil = 0;

    for (int i = 0; i < argc - 2; i++) {

        service_client::Operation srvJumlah, srvKali, srvPangkat;

        srvPangkat.request.a = atoi(argv[1]);
        srvPangkat.request.b = argc - 3 - i;

        this->perpangkatan_client.call(srvPangkat);

        srvKali.request.a = atoi(argv[i + 2]);
        srvKali.request.b = (int)srvPangkat.response.result;

        this->perkalian_client.call(srvKali);

        srvJumlah.request.a = hasil;
        srvJumlah.request.b = (int)srvKali.response.result;

        this->penjumlahan_client.call(srvJumlah);

        hasil = (int)srvJumlah.response.result;

    }

    return hasil;

}

int main(int argc, char **argv) {

    ros::init(argc, argv, "clientNode");

    Client client;

    if (argc < 3) {

        ROS_INFO("usage: operator_client x, koefisien_1, koefisien_2, ..., konstanta ");

        return 1;

    } else {

        ROS_INFO("%d", client.fungsi(argc, argv));

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
// rosrun service_client operator_client_node 3 1 2 3 4
// [ INFO] [1625549657.308922624]: 58
