/*
COPYRIGHT 2026 Zaripov Azat <zanelane87@gmail.com>
*/

#include <string>
#include <iostream>
#include <cxxopts.hpp>

int main(int argc, char* argv[]) {
    cxxopts::Options options(argv[0], "Program description goes here");

    options.add_options()
        ("h,help", "Print usage")
        ("i,input", "Specify intput file path")
        ("o,out", "Specify output file path", cxxopts::value<std::string>())
        ("c,compress", "Compress file")
        ("d,decompress", "Decompress file");

    auto result = options.parse(argc, argv);

    // This prints the beautifully formatted help menu automatically!
    if (result.count("help")) {
        std::cout << options.help() << std::endl;
        return 0;
    }

    // if (result.count("file")) {
    //     std::cout << "File: " << result["file"].as<std::string>() << "\n";
    // }

    return 0;
}
