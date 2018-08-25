#include <boost/asio.hpp>
#include <boost/program_options.hpp>

#include <iostream>

int main(int argc, char** argv) {
    namespace po = boost::program_options;
    po::options_description desc;
    desc.add_options()
        ("help", "produce help message")
        ("host", po::value<std::string>(), "host name");
    
    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count("help")) {
        std::cout << desc << "\n";
        return 0;
    }

    if (vm.count("host")) {
        std::string const& host = vm["host"].as<std::string>();
        boost::asio::io_service io_service;
        boost::asio::ip::tcp::resolver resolver(io_service);
        boost::asio::ip::tcp::resolver::query query(host, "80");
        boost::asio::ip::tcp::resolver::iterator iter;
        try {
            iter = resolver.resolve(query);
        } catch (boost::system::system_error& e) {
            std::cout << e.what() << std::endl;
            return 1;
        }
        boost::asio::ip::tcp::resolver::iterator end;
        std::cout << "host name: " << host << std::endl;
        for (size_t i = 0; iter != end; ++iter, ++i) {
            std::cout << "ip#" << i << ": " << iter->endpoint().address() << std::endl;
        }
        return 0;
    }
    return 0;
}