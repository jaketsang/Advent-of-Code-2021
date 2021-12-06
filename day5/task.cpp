#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

class Vent {
public:
Vent(int size) {
    std::vector<int> a(size, 0);
    std::vector<std::vector<int>> v(size, a); 
    mVents = v;
};

void rowLine(int a, int b, int c) {
    int lower = std::min(a, b);
    int upper = std::max(a, b) + 1;
    for (int i = lower; i < upper; i++) {
        mVents[c][i] += 1;
        if (mVents[c][i] == 2) {
            mOverlap++;
        }
    }
}

void colLine(int a, int b, int c) {
    int lower = std::min(a, b);
    int upper = std::max(a, b) + 1;
    for (int i = lower; i < upper; i++) {
        mVents[i][c] += 1;
        if (mVents[i][c] == 2) {
            mOverlap++;
        }
    }
}

void printGrid() {
    for (int i = 0; i < mVents.size(); i++) {
        for (int j = 0; j < mVents.size(); j++) {
            std::cout << mVents[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

int gridSize() {
    return mVents.size();
}

int getOverlap() {
    return mOverlap;
}

void simpleDiagonalLine(int start, int end) {
    int lower = std::min(start, end);
    int upper = std::max(start, end) + 1;
    for (int i = lower; i < upper; i++) {
        mVents[i][i] += 1;
        if (mVents[i][i] == 2) {
            mOverlap++;
        }
    }
}

void diagonalLine(std::vector<int> coords, int diff) {
    int xSign = 1; int ySign = 1;
    if (coords[2] - coords[0] < 0) {
        xSign = -1;
    }
    if (coords[3] - coords[1] < 0) {
        ySign = -1;
    }
    
    for (int i = 0; i <= diff; i++) {
        int y = coords[0] + i * xSign;
        int x = coords[1] + i * ySign;
        mVents[x][y] += 1;

        if (mVents[x][y] == 2) {
            mOverlap++;
        }
    }
}

private:
std::vector<std::vector<int>> mVents {0};
int mOverlap = 0;
};

std::vector<int> lowerBound(std::string point) {
    std::vector<int> points {};
    point.append("\0");

    std::string::size_type p = point.find(',');
    while (points.size() != 4) {
        if (points.size() == 3) {
            points.push_back(std::stoi(point));
            break;
        }
        if (p != std::string::npos) {
            points.push_back(std::stoi(point.substr(0, p)));
            point.erase(0, (int) p + 1);
        }

        if (point.at(0) == '-') {
            point.erase((int) point.find('-'), 3);
        }

        if (point.find(' ') != std::string::npos) {
            p = point.find(' ');
        } else {
            p = point.find(',');
        }
    }
    return points;
}

int largest(std::string name) {
    std::ifstream file(name);
    int largest = 0;
    for (std::string str; std::getline(file, str);) {
        std::vector<int> coords = lowerBound(str);
        int bound = *(std::max_element(coords.begin(), coords.end()));
        largest = std::max(largest, bound);
    }
    file.close();
    return largest;
}

int main() {
    int size = largest("input.txt") + 1;

    Vent vents = Vent{size}; 

    std::ifstream file("input.txt");
    for (std::string str; std::getline(file, str);) {
        
        // get coords
        std::vector<int> coords = lowerBound(str);

        std::cout << coords[0] << "," << coords[1] << "," << coords[2] << "," << coords[3] << std::endl;
                
        // Draw lines
        if (coords[1] == coords[3]) {
            vents.rowLine(coords[0], coords[2], coords[1]);
        } else if (coords[0] == coords[2]) {
            vents.colLine(coords[1], coords[3], coords[0]);
        } else if (coords[0] == coords[1] && coords[2] == coords[3]) {
            vents.simpleDiagonalLine(coords[0], coords[2]);
        } else if (std::abs(coords[0] - coords[2]) == std::abs(coords[1] - coords[3])) {
            vents.diagonalLine(coords, std::abs(coords[0] - coords[2]));
        }

        
    }
    std::cout << "score " << vents.getOverlap() << std::endl;
    file.close();
}