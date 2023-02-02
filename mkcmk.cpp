#include <fstream>
#include <iostream>

int main(int argc, char** argv) {
    if (argc == 1) {
        std::cerr << "error: Need an executable name.\n";
        return EXIT_FAILURE;
    }
    if (argc > 2) {
        std::cerr << "error: Too many arguments.\n";
        return EXIT_FAILURE;
    }

    const auto name = argv[1];
    std::ofstream ofs{"CMakeLists.txt"};

    ofs << "cmake_minimum_required(VERSION 3.16)\n\nproject(" << name << ")\n\n";
    ofs << "add_executable(" << name << " " << name << ".cpp)\n";
    ofs << "set_property(TARGET " << name << " PROPERTY CXX_STANDARD 20)\n";
}
