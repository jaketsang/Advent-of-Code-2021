#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

int fuelUsed(int src, int dest) {
    int s = 0;
    for (int i = 0; i < std::abs(src - dest); i++) {
        s += i + 1;
    }
    return s;
}

// Median of positions
int part1(std::vector<int> crabs) {
    std::sort(crabs.begin(), crabs.end());
    int sum = 0;
    int mid = std::ceil(crabs.size() / 2);

    for (auto c : crabs) {
        sum += std::abs(crabs[mid] - c);
    }
    return sum;
}

// Average of positions
int part2(std::vector<int> crabs) {
    // The ceil or floor
    double avg = 0;
    for (auto c : crabs) {
        avg += c;
    }
    
    int avg2 = std::floor(avg / crabs.size());
    avg = std::ceil(avg / crabs.size());

    int fuel = 0;
    int fuel2 = 0;
    for (auto c : crabs) {
        fuel += fuelUsed(c, avg);
        fuel2 += fuelUsed(c, avg2);
    }
    
    return std::min(fuel, fuel2);
}

int main() {
    std::ifstream file("input.txt");

    std::vector<int> positions {};

    for (std::string s; std::getline(file, s, ',');) {
        positions.push_back(std::stoi(s));
    }

    std::cout << "part1: " << part1(positions) << std::endl;
    std::cout << "part2: " << part2(positions) << std::endl;

    file.close();
}