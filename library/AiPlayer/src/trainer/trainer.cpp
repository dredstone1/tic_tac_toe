#include "../../include/Trainer/trainer.hpp"
#include "database/dataBase.hpp"
#include <chrono>
#include <iostream>
#include <matplot/matplot.h>

using namespace matplot;

void Trainer::print_progress_bar(int current, int total) {
    float progress = (float)current / total;
    int progress_percentage = int(progress * 100.0);

    if (progress_percentage != last_progress) {
        int pos = BAR_WIDTH * progress;
        last_progress = progress_percentage;

        ostringstream oss;
        oss << "[";
        for (int i = 0; i < BAR_WIDTH; ++i) {
            if (i < pos)
                oss << "=";
            else if (i == pos)
                oss << ">";
            else
                oss << " ";
        }
        oss << "] " << progress_percentage << " %\r";

        cout << oss.str();
        cout.flush();
    }
}

int Trainer::train() {
    cout << "Training AI" << endl;

    auto start = chrono::high_resolution_clock::now();
    const double graph_resolution = (GRAPH_RESOLUTION > batch_count) ? batch_count : GRAPH_RESOLUTION;
    const int graph_draw_interval = batch_count / graph_resolution;
    vector<double> errors(graph_resolution, 0.0);
    double error = 0.0;

    for (int loop_index = 0; loop_index < batch_count; loop_index++) {
        vector<TrainBoard> boards;
        boards.resize(batch_size);
        for (int i = 0; i < batch_size; i++) {
            boards[i] = dataBase.get_next_board();
        }

        error += backPropagation.run_back_propagation(boards);

        if ((loop_index + 1) % graph_draw_interval == 0) {
            errors[loop_index / graph_draw_interval] = error / graph_draw_interval;
            error = 0.0;
            print_progress_bar(loop_index + 1, batch_count);
        }
    }

    auto end = chrono::high_resolution_clock::now();
    int time_taken = chrono::duration_cast<chrono::seconds>(end - start).count();
    int minutes = time_taken / SECONDS_IN_MINUTE;
    int seconds = time_taken % SECONDS_IN_MINUTE;
    int time_taken_milliseconds = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << endl
         << "Training Done!" << endl
         << "Training time: " << minutes << " minutes " << seconds << " seconds" << " (" << time_taken_milliseconds << " ms)" << endl;
    title("cost function");
    plot(errors);
    save("./graph.svg");
    show();

    return 0;
}

Trainer::Trainer(string _file_name, AiModel *_model, int _batch_size, int _batch_count, double _learning_rate)
    : dataBase(_file_name), backPropagation(*_model, _learning_rate) {
    file_name = _file_name;
    model = _model;
    batch_size = _batch_size;
    batch_count = _batch_count;
    last_progress = 0;
}
