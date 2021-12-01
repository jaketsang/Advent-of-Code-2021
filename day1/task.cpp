#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <numeric>

int main() {
    std::ifstream file("input.txt");
    std::string str;
    //int count = 0;

    // Part 1
    // std::string prev = "";

    // while (std::getline(file, str)) {
    //     if (prev != "") {
    //         if (std::stoi(str) > std::stoi(prev)) {
    //             count++;
    //         }
    //     }
    //     prev = str;
    // }

    // Part 2
    std::vector<int>values {};
    while (std::getline(file, str)) {
        values.push_back(static_cast<int>(std::stoi(str)));
    }

    // check sum of 3s 
    int count = 0;
    int size = static_cast<int>(values.size());
    for (int i = 0; i < size - 3; i++) {
        int a = values.at(i) + values.at(i+1) + values.at(i+2);
        int b = values.at(i+1) + values.at(i+2) + values.at(i+3);
        if (a < b) {
            count++;
        }
    }

    std::cout << count << std::endl;
    file.close();
}