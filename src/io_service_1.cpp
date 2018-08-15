#include <iostream>

#include <boost/asio.hpp>

#include <gtest/gtest.h>


TEST(IO_SERVICE, Test1) {
    /*
    * Nothing to do
    */

    boost::asio::io_service io_service;
    io_service.run();
    std::cout << "Do you reckon this line displays?" << std::endl;
}


TEST(IO_SERVICE, Test2) {
    /*
    * blocked
    */
    boost::asio::io_service io_service;
    // boost::asio::io_service::work work( io_service );
    io_service.run();
    std::cout << "Do you reckon this line displays?" << std::endl;
}


TEST(IO_SERVICE, Test3) {
    /*
    * not blocked
    */
    boost::asio::io_service io_service;
    boost::asio::io_service::work work(io_service);
    for (size_t i = 0; i < 42; ++i) {
        io_service.poll();
        std::cout << "Counter: " << i << std::endl;
    }
}


TEST(IO_SERVICE, Test4) {
    /*
    * do discard work we can simply use smart pointer
    */
    boost::asio::io_service io_service;
    std::shared_ptr<boost::asio::io_service::work> work{new boost::asio::io_service::work(io_service)};
    work.reset();
    io_service.run();
    std::cout << "Do you reckon this line displays?" << std::endl;
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
