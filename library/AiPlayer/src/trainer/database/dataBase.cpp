#include "dataBase.hpp"
#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>
#include <ostream>
#include <random>
#include <string>
#include <vector>

DataBase::DataBase(string file_name) {
    this->current_board = 0;
    this->load(file_name);
}

int DataBase::load(string file_name) {
    ifstream file(file_name + ".txt");
    if (!file.is_open()) {
        cout << "File not found" << endl;
        return 1;
    }

    string line;
    getline(file, line);
    file.close();
    char *line_ = &line[0];
    int board_count = atoi(strtok(line_, " "));

    for (int i = 0; i < board_count; i++) {
        TrainBoard board;
        for (int j = 0; j < 9; j++) {
            board.board.push_back(atof(strtok(NULL, " ")));
        }
        for (int j = 0; j < 9; j++) {
            board.prediction_target.push_back(atof(strtok(NULL, " ")));
        }
        this->train_boards.push_back(board);
    }

    return 0;
}

TrainBoard &DataBase::get_next_board() {
    if (train_boards.size() <= current_board) {
        current_board = 0;
        shuffle();
    }
    return train_boards.at(this->current_board++);
}

void DataBase::shuffle() {
    random_device rd;
    default_random_engine rng(rd());
    std::shuffle(this->train_boards.begin(), this->train_boards.end(), rng);
}
