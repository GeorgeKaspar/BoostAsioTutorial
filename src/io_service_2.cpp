#include <iostream>

#include <boost/asio.hpp>
#include <boost/thread.hpp>

#include <gtest/gtest.h>

void WorkerThread(boost::shared_ptr<boost::asio::io_service> io_service) {
	std::cout << "Thread Start" << std::endl;
	io_service->run();
	std::cout << "Thread Finish" << std::endl;
}


TEST(ThreadPool, Test1) {
    boost::shared_ptr<boost::asio::io_service> io_service(new boost::asio::io_service());
	boost::shared_ptr<boost::asio::io_service::work> work(new boost::asio::io_service::work(*io_service));

    std::cout << "Press [return] to exit." << std::endl;

    boost::thread_group worker_threads;
    for( int x = 0; x < 4; ++x ) {
        worker_threads.create_thread(boost::bind(&WorkerThread, io_service));
    }

    std::cin.get();
    io_service->stop();
    worker_threads.join_all();
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
