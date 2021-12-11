#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

int part1(std::stringstream *data) {
    int sum = 0;
    for (std::string str; std::getline((*data), str);) {
        std::vector<char> c;
        for (auto s : str) {
            if (s == '(' || s == '[' || s == '{' || s== '<') {
                c.push_back(s);
            } else if ((s == ')' && c.back() == '(') || (s == ']' && c.back() == '[')
                || (s == '}' && c.back() == '{') || (s == '>' && c.back() == '<')) {
                c.pop_back();
            } else {
                if (s == ')') sum += 3;
                else if (s == ']') sum += 57;
                else if (s == '}') sum += 1197;
                else if (s == '>') sum += 25137;
                c.pop_back();
            }
        }
    }
    return sum;
}

bool isCorrupt(std::string data) {
    std::vector<char> c;
    for (auto s : data) {
        if (s == '(' || s == '[' || s == '{' || s== '<') {
            c.push_back(s);
        } else if ((s == ')' && c.back() == '(') || (s == ']' && c.back() == '[')
            || (s == '}' && c.back() == '{') || (s == '>' && c.back() == '<')) {
            c.pop_back();
        } else {
            return true;
        }
    }
    return false;
}

std::string reduce(std::string data) {
    std::vector<char> c;
    for (auto s : data) {
        if (s == '(' || s == '[' || s == '{' || s== '<') {
            c.push_back(s);
        } else if ((s == ')' && c.back() == '(') || (s == ']' && c.back() == '[')
            || (s == '}' && c.back() == '{') || (s == '>' && c.back() == '<')) {
            c.pop_back();
        }
    }
    std::string s(c.begin(), c.end());
    return s;
}

unsigned long long int part2(std::stringstream *data) {
    std::vector<unsigned long long int> scores;
    for (std::string str; std::getline((*data), str);) {
        if (isCorrupt(str)) {
            //std::cout << str << " corrupt" << std::endl;
            continue;
        }
        std::string reduced = reduce(str);
        std::cout << reduced << " ";
        unsigned long long int t = 0;
        for (int i = reduced.size() - 1; i >= 0; i--) {
            if (reduced[i] == '(') {
                std::cout << ")";
                t *= 5;
                t += 1;
            } else if (reduced[i] == '[') {
                std::cout << "]";
                t *= 5;
                t += 2;
            } else if (reduced[i] == '{') {
                std::cout << "}";
                t *= 5;
                t += 3;
            } else if (reduced[i] == '<') {
                std::cout << ">";
                t *= 5;
                t += 4;
            }
        }
        scores.push_back(t);
        std::cout << " added " << t << std::endl;
    }
    // for (auto s : scores) {
    //     std::cout << s << std::endl;
    // }
    std::sort(scores.begin(), scores.end());
    
    return scores[scores.size() / 2.0];
}

int main() {
    std::ifstream file("input.txt");
    std::stringstream data;
    data << file.rdbuf();

    //std::cout << "part1: " << part1(&data) << std::endl;    
    std::cout << "part2: " << part2(&data) << std::endl;  

}