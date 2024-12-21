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

    cout << "AI Game" << endl;

    AiModel *model = NULL;
    if (argc > 1 && argv[1][0] == 'l') {
        model = new AiModel("model1");
    } else if (argc > 1 && argv[1][0] == 's') {
        model = new AiModel();
        model->save("model1");
    } else if (argc > 1 && argv[1][0] == 't') {
        model = new AiModel();
        Trainer trainer("database", model, 10, 10000, 0.1);
        trainer.train();
        model->save("model1");
    }

    if (model == NULL) {
        model = new AiModel();
    }

    AiPlayer aiPlayer(model);
    Game game(&StandardPlayer1, &aiPlayer);
    game.run();
    delete model;

    return 0;
}
