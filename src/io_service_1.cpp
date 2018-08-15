#include <iostream>

#include <boost/asio.hpp>

#include <gtest/gtest.h>


TEST(IO_SERVICE, Test1) {
    boost::asio::io_service io_service;
    io_service.run();
    std::cout << "Do you reckon this line displays?" << std::endl;
}


TEST(IO_SERVICE, Test2) {
    /*
    * blocked
    */
    boost::asio::io_service io_service;
    boost::asio::io_service::work work( io_service );
    io_service.run();
    std::cout << "Do you reckon this line displays?" << std::endl;
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
