#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

std::vector<int> onesCount(std::vector<std::string> data) {
    std::vector<int> freq {};
    for (auto s : data) {
        for (int i = 0; i < s.size(); i++) {
            if (freq.size() == i) {
                freq.push_back(0);
            }
            if (s.at(i) == '1') {
                freq[i]++;
            }
        }
    }
    return freq;
}

std::vector<std::string> parseData(std::string filename) {
    std::ifstream file(filename);
    std::vector<std::string> values {};
    for (std::string str; std::getline(file, str);) {
        values.push_back(str);
    }
    file.close();
    return values;
}

std::vector<std::string> valuesBitCriteria(std::vector<std::string> data, int position, char criteria) {
    std::vector<std::string> reduced {};
    for (auto s : data) {
        if (s.at(position) == criteria) {
            reduced.push_back(s);
        }
    }
    return reduced;
}

std::vector<std::string> reduceReport(std::vector<std::string> data, char mostCommon, char leastCommon, int i) {   
    if (data.size() == 1) {
        return data;
    }

    std::vector<int> oneFrequency = onesCount(data);
    int length = data.size();
    char criteria = leastCommon;
    if (i < oneFrequency.size()) {
        
        if (oneFrequency.at(i) >= std::ceil(length/2.0)) {

            criteria = mostCommon;
        }
    }
    std::vector<std::string> reduced = valuesBitCriteria(data, i, criteria);
    return reduceReport(reduced, mostCommon, leastCommon, ++i);
}

int binaryToDecimal(std::string binary) {
    int value = 0;
    for (int i = 0; i < binary.size(); i++) {
        if (binary.at(binary.size() - i - 1) == '1') {
            value += std::pow(2, i);
        }
    }
    return value;
}

void part1(std::vector<std::string> data) {
    int gamma = 0; int epsilon = 0;
    std::vector<int> oneFrequency = onesCount(data);
    int length = data.size();

    for (int i = 0; i < oneFrequency.size(); i++) {
        if (oneFrequency.at(oneFrequency.size() - i - 1) > length/2) {
            gamma += std::pow(2, i);
        } else {
            epsilon += std::pow(2, i);
        }
    }
    std::cout << "part 1: " << gamma << " x " << epsilon << " = " << gamma * epsilon << std::endl;
}

void part2(std::vector<std::string> data) {
    int oxygen = binaryToDecimal(reduceReport(data, '1', '0', 0).at(0));
    int co2 = binaryToDecimal(reduceReport(data, '0', '1', 0).at(0));
    
    std::cout << "part 2: " << oxygen << " x " << co2 << " = " << oxygen * co2 << std::endl;
}

int main() {
    part1(parseData("input.txt"));
    part2(parseData("input.txt"));
}

