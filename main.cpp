#include <AiPlayer/AiModel.hpp>
#include <AiPlayer/AiPlayer.hpp>
#include <StandardPlayer/StandardPlayer.hpp>
#include <TicTacToe/game.hpp>
#include <Trainer/trainer.hpp>
#include <iostream>
#include <string>

using namespace TicTacToe;
using namespace std;

int main(int argc, char *argv[]) {
    StandardPlayer StandardPlayer1;
    cout << "Start Game" << endl;

    if (argc > 1 && argv[1][0] == '2') {
        cout << "2 Players Game" << endl;
        StandardPlayer StandardPlayer2;
        Game game(&StandardPlayer1, &StandardPlayer2);
        game.run();
        return 0;
    }

    std::cout << "AI Game" << std::endl;

    AiModel model;
    AiPlayer aiPlayer(&model);
    if (argc > 1 && argv[1][0] == 'l') {
        model.load(string("model1"));
    } else if (argc > 1 && argv[1][0] == 's') {
        model.save(string("model1"));
    } else if (argc > 1 && argv[1][0] == 't') {
        Trainer trainer("database", &model);
        trainer.train();
        model.save(string("model1"));
    }
    Game game(&StandardPlayer1, &aiPlayer);
    game.run();

    return 0;
}
