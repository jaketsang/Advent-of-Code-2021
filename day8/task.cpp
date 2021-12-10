#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int part1(std::string input) {
    size_t del = input.find("|");
    input = input.substr(del + 2, input.size());
    int sum = 0;
    size_t i = 0;
    input.append(" ");
    while ((i = input.find(" ")) != std::string::npos) {
        std::string str = input.substr(0, i);
        //std::cout << str << std::endl;
        if (str.size() == 2 || str.size() == 4 || str.size() == 3 || str.size() == 7) {
            sum++;
        }
        input.erase(0, i + 1);   
    }
    return sum;
}

int part2(std::string input) {
    std::string value[10] {};
    std::vector<std::string> sixes; std::vector<std::string> fives;
    size_t i = 0;
    while ((i = input.find(" ")) != std::string::npos) {
        std::string str = input.substr(0, i);
        if (str == "|") {
            input.erase(0, 2);
            break;
        }

        // sort 
        std::sort(str.begin(), str.end());

        if (str.size() == 2) {
            value[1] = str;
        } else if (str.size() == 4) {
            value[4] = str;
        } else if (str.size() == 3) {
            value[7] = str;
        } else if (str.size() == 7) {
            value[8] = str;
        } else if (str.size() == 6) {
            sixes.push_back(str);
        } else if (str.size() == 5) {
            fives.push_back(str);
        }
        input.erase(0, i + 1);   
    }

    // figuring out sixes and fives
    for (auto s : sixes) {

        if (s.find(value[4][0]) != std::string::npos && s.find(value[4][1]) != std::string::npos
            && s.find(value[4][2]) != std::string::npos && s.find(value[4][3]) != std::string::npos) {
                value[9] = s;
        } else if (s.find(value[1][0]) != std::string::npos && s.find(value[1][1]) != std::string::npos) {
            value[0] = s;
        } else {
            value[6] = s;
        }
    }

    for (auto s : fives) {
        // might not be in the same order so check each char
        if (s.find(value[1][0]) != std::string::npos && s.find(value[1][1]) != std::string::npos) {
            value[3] = s;
        } else if (s.size() == 5 && value[6].find(s[0]) != std::string::npos && value[6].find(s[1]) != std::string::npos
            && value[6].find(s[2]) != std::string::npos && value[6].find(s[3]) != std::string::npos
            && value[6].find(s[4]) != std::string::npos) {
                value[5] = s;
        } else {
            value[2] = s;
        }
    }

    // sort the strings
    for (int i = 0; i < 10; i++) {
        std::sort(value[i].begin(), value[i].end());
    }

    input.append(" ");
    int multiplier = 1000;
    int sum = 0;
    while ((i = input.find(" ")) != std::string::npos) {
        std::string str = input.substr(0, i);

        std::sort(str.begin(), str.end());

        for (int i = 0; i < 10; i++) {
            if (value[i] == str) {
                sum += i * multiplier;
                multiplier /= 10;
            }
        }

        input.erase(0, i + 1);   
    }

    return sum;
}

int main() {
    std::ifstream file("input.txt");

    int sum = 0;
    int sum2 = 0;
    for (std::string str; std::getline(file, str);) {
        sum += part1(str);
        sum2 += part2(str);
    }
    
    std::cout << "part1: " << sum << std::endl;
    std::cout << "part2: " << sum2 << std::endl;
    

}