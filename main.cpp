#include <AiPlayer/AiModel.hpp>
#include <AiPlayer/AiPlayer.hpp>
#include <StandardPlayer/StandardPlayer.hpp>
#include <TicTacToe/game.hpp>
#include <iostream>

using namespace TicTacToe;
using namespace std;

int main(int argc, char *argv[]) {
    StandardPlayer StandardPlayer1;
    cout << "Start Game" << endl;

    if (argc > 1 && string(argv[1]) == "2") {
        cout << "2 Players Game" << endl;
        StandardPlayer StandardPlayer2;
        Game game(&StandardPlayer1, &StandardPlayer2);
        game.run();
        return 0;
    }

    std::cout << "AI Game" << std::endl;
    AiPlayer aiPlayer;
    Game game(&StandardPlayer1, &aiPlayer);
    game.run();

    return 0;
}
