#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

class Board {
public:
    Board(std::string board) {
        toMatrix(board);
    }
    std::string getBoard() {
        std::string s = "";
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                s.append(std::to_string(mBoard[i][j]));
                s.append(",");
            }
        }
        return s;
    }

    void printMarked() {
        std::cout << std::endl;
        std::string s = "";
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                s.append(std::to_string(marked[i][j]));
                s.append(" ");
            }
            s.append("\n");
        }
        std::cout << s << std::endl;
    }

    void toMatrix(std::string board) {
        std::stringstream input{board};
        int i = 0;
        std::vector<int> row {0,0,0,0,0};
        for (std::string s; std::getline(input, s, ' ');) {
            if (s.compare(" ") == 0 || s.compare("") == 0) {
                continue;
            }
            row.at(i % 5) = std::stoi(s);
            if ((i+1) % 5 == 0) {
                mBoard.push_back(row);
            }
            i++;
        }
    }
    // check column
    bool columnBingo(int c) {
        for (int i = 0; i < 5; i++) {
            if (marked[i][c] == 0) {
                return false;
            }
        }
        return true;
    }
    
    // check row
    bool rowBingo(int r) {
        for (int i = 0; i < 5; i++) {
            if (marked[r][i] == 0) {
                return false;
            }
        }
        return true;
    }

    int score() {
        int sum = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (marked[i][j] == 0) {
                    sum += mBoard[i][j];
                }
            }
        }
        return sum * multiplier;
    }

    // set value marked
    int mark(int c) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (c == mBoard[i][j]) {
                    multiplier = c;
                    marked[i][j] = 1;
                    //printMarked();
                    if (columnBingo(j) || rowBingo(i)) {
                        return score();
                    }
                }
            }
        }
        return 0;
    }

private:
    std::vector<std::vector<int>> mBoard;
    int marked[5][5] {};
    int multiplier = 0;
};

int main() {
    std::ifstream file("input.txt");

    std::vector<Board> boards {};
    std::string values {};
    std::getline(file, values);

    // Initialise all bingo boards
    for (std::string str; std::getline(file, str);) {
        std::string board = "";
        for (int i = 0; i < 5; i++) {
            std::getline(file, str);
            board.append(str);
            board.append(" ");
        }
        boards.push_back(Board(board));
    }

    // go through all values until bingo 
    std::stringstream numbers(values);
    for (std::string s; std::getline(numbers, s, ',');) {
        // go through all Boards and mark value
        std::vector<Board>::iterator it = boards.begin();
        while (it != boards.end()) { // can't ues auto b : boards 
            int solution = it->mark(std::stoi(s));
            if (solution != 0) {
                std::cout << solution << std::endl;
                it = boards.erase(it);
            } else {
                ++it;
            }
        }
    }
    file.close();
}

