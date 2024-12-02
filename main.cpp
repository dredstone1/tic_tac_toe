#include <AiPlayer/AiModel.hpp>
#include <AiPlayer/AiPlayer.hpp>
#include <StandardPlayer/StandardPlayer.hpp>
#include <TicTacToe/game.hpp>

using namespace TicTacToe;
using namespace std;

int main(int argc, char *argv[]) {
    // StandardPlayer StandardPlayer1;
    // StandardPlayer StandardPlayer2;
    // cout << "Start Game" << endl;
    //
    // Game game(&StandardPlayer1, &StandardPlayer2);
    //
    // game.run();

    StandardPlayer player;
    AiPlayer aiPlayer;
    Game game(&player, &aiPlayer);

    game.run();

    return 0;
}
