/*
 * Simple Compressor - util to compress files
 *
 * Copyright (C) 2026 Zaripov Azat
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <string>
#include <stdexcept>
#include <iostream>
#include <cxxopts.hpp>

int main(int argc, char* argv[]) {
    cxxopts::Options options(argv[0], "Program description goes here");

    options.add_options()
        ("h,help", "Print usage")
        ("i,input", "Specify intput file path")
        ("o,output", "Specify output file path", cxxopts::value<std::string>())
        ("c,compress", "Compress file")
        ("d,decompress", "Decompress file");

    cxxopts::ParseResult result;
    try {
        result = options.parse(argc, argv);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }

    if (result.count("help")) {
        std::cout << options.help() << std::endl;
        return 0;
    }

    if (!result.count("input")) {
        std::cout << "No input file" << std::endl;
        return 1;
    }

    if (!result.count("output")) {
        std::cout << "No output file" << std::endl;
        return 1;
    }

    return 0;
}
