#include <iostream>
#include <functional>
#include <string>

#include <boost/asio.hpp>

#include <gtest/gtest.h>


void caller(std::function<void(void)> const& f) {
    f();
}


void f1(int n) {
    std::cout << n << std::endl;
}


void f2(int n, std::string const& s) {
    std::cout << n << s << std::endl;
}


TEST(BIND, Test1) {
    auto _f1 = std::bind(f1, 3);
    auto _f2 = std::bind(f2, 3, "hello");
    caller(_f1);
    caller(_f2);
}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}