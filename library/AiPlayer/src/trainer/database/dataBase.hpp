#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <string>
#include <vector>
using namespace std;

struct TrainBoard {
    vector<double> board;
    vector<double> prediction_target;
};

class DataBase {
  private:
    vector<TrainBoard> train_boards;
    int current_board;
    int load(string file_name);
    void shuffle();

  public:
    DataBase(string _file_name);
    TrainBoard &get_next_board();
    ~DataBase() = default;
    int get_train_boards_count() { return train_boards.size(); }
};

#endif // DATABASE_HPP
