#include "../../include/Trainer/trainer.hpp"
#include "database/dataBase.hpp"
#include <chrono>
#include <iostream>
#include <matplot/matplot.h>

using namespace matplot;

void Trainer::print_progress_bar(int current, int total) {
    int bar_width = 70;
    float progress = (float)current / total;
    int pos = bar_width * progress;

    std::cout << "[";
    for (int i = 0; i < bar_width; ++i) {
        if (i < pos)
            std::cout << "=";
        else if (i == pos)
            std::cout << ">";
        else
            std::cout << " ";
    }
    std::cout << "] " << int(progress * 100.0) << " %\r";
    std::cout.flush();
}

int Trainer::train() {
    cout << "Training AI" << endl;

    auto start = chrono::high_resolution_clock::now();

    vector<double> errors(graph_resolution, 0.0);
    double error = 0.0;
    for (int loop_index = 0; loop_index < this->batch_count; loop_index++) {
        vector<TrainBoard> boards;
        boards.resize(this->batch_size);
        for (int i = 0; i < this->batch_size; i++) {
            boards[i] = this->dataBase.get_next_board();
        }
        double _error = this->backPropagation.run_back_propagation(boards);
        error += _error;
        if ((loop_index + 1) % (this->batch_count / graph_resolution) == 0) {
            errors[loop_index / (this->batch_count / graph_resolution)] = error / ((double)this->batch_count / graph_resolution);
            error = 0.0;
        }
        print_progress_bar(loop_index + 1, this->batch_count);
    }

    cout << endl;
    auto end = chrono::high_resolution_clock::now();
    int time_taken = chrono::duration_cast<chrono::seconds>(end - start).count();
    int minutes = time_taken / 60;
    int seconds = time_taken % 60;
    cout << "Training Done" << endl;
    cout << "Training time: " << minutes << " minutes " << seconds << " seconds" << endl;

    title("cost function");
    plot(errors, "r-");
    save("./graph.png");
    save("./graph.svg");
    show();
    return 0;
}

Trainer::Trainer(string file_name, AiModel *_model, int batch_size, int batch_count, double learning_rate)
    : dataBase(file_name), backPropagation(*_model, learning_rate) {
    this->file_name = file_name;
    this->model = _model;
    this->batch_size = batch_size;
    this->batch_count = batch_count;
}
