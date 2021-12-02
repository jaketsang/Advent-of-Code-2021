#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

int main() {
    std::ifstream file("input.txt");
    int horizontal = 0; int depth = 0; int aim = 0;
    
    // Part 1
    // for (std::string move; std::getline(file, move);) {
    //     if (move.find("forward") != std::string::npos) {
    //         horizontal += std::stoi(move.substr(8, move.size()));
    //     } else if (move.find("up") != std::string::npos) {
    //         depth -= std::stoi(move.substr(3, move.size()));
    //     } else if (move.find("down") != std::string::npos) {
    //         depth += std::stoi(move.substr(5, move.size()));
    //     }
    // }

    // Part 2
    for (std::string move; std::getline(file, move);) {
        if (move.find("forward") != std::string::npos) {
            horizontal += std::stoi(move.substr(8, move.size()));
            depth += aim * std::stoi(move.substr(8, move.size()));
        } else if (move.find("up") != std::string::npos) {
            aim -= std::stoi(move.substr(3, move.size()));
        } else if (move.find("down") != std::string::npos) {
            aim += std::stoi(move.substr(5, move.size()));
        }
    }

    std::cout << horizontal * depth << std::endl;
    file.close();
}