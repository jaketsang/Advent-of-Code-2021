#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <numeric>

int main() {
    std::ifstream file("input.txt");

    // store the number of fissh in a particular cycle
    std::vector<long long int> fishes(9, 0);
    // Initialise fish
    for (std::string str; std::getline(file, str, ',');) {
        fishes.at(std::stoi(str))++;
    }
    
    // get input for days
    int days;
    std::cin >> days;

    for (int i = 0; i < days; i++) {
        unsigned long long int newFishes = fishes.at(0);
        for (int j = 0; j < 8; j++) {
            fishes.at(j) = fishes.at(j+1);
        }
        fishes.at(8) = newFishes;
        fishes.at(6) += newFishes;

    }

    unsigned long long int sum = 0;
    for (int i = 0; i < 9; i++) {
        sum += fishes.at(i);
    }

    std::cout << "population: " << sum << std::endl;
}