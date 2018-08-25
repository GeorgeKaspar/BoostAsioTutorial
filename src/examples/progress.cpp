#include <boost/progress.hpp>

#include <gtest/gtest.h>

#include <chrono>
#include <thread>


TEST(Progress, Test1) {
    int const N = 10;
    boost::progress_display progress(N);
    for (size_t i = 0; i < N; ++i) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        ++progress;
    }
}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}