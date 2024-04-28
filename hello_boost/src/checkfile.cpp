#include <iostream>
#include <boost/filesystem.hpp>

namespace boostfs = boost::filesystem;

int main(int argc, char *argv[]){
    if (argc <= 1) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    boostfs::path p(argv[1]);

    if (boostfs::exists(p)) {
        std::cout << "File " << p << " exists." << std::endl;
    }else {
        std::cout << "File " << p << " does not exist." << std::endl;
    }

    return 0;
}