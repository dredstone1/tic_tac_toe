#include "../include/TicTacToe/game.hpp"
#include "BoardGrid.hpp"
#include <iostream>

using namespace std;

namespace TicTacToe {

Game::Game(Player *playerX_, Player *playerO_)
    : playerO(EMPTY), playerX(EMPTY) {
    this->board = new Board();

    playerX.SetPlayer(playerX_, X, this->board);
    playerO.SetPlayer(playerO_, O, this->board);
}

Game::~Game() { delete this->board; }

void Game::run() {
    cout << "Start Game loop" << endl;
    this->board->draw();
    PlayerAdapter *currentPlayer = &playerX;

    while (this->board->GetBoardState() == Continue) {
        int move = currentPlayer->getMove();
        if (move < 0 || move > 8 ||
            this->board->get(move / 3, move % 3) != EMPTY) {
            cout << "Invalid move: << " << move << endl;
            continue;
        }

        this->board->set(move / 3, move % 3, currentPlayer->getPlayerMode());
        this->board->draw();
        currentPlayer = (currentPlayer == &playerX) ? &playerO : &playerX;
    }

    switch (this->board->GetBoardState()) {
    case WinX:
        playerX.updateScore(playerX.getScore() + 1);
        playerX.UserWin();
        playerO.UserLost();
        break;
    case WinO:
        playerO.updateScore(playerO.getScore() + 1);
        playerO.UserWin();
        playerX.UserLost();
        break;
    case Draw:
        playerO.UserDraw();
        playerX.UserDraw();
        break;
    default:
        break;
    }
    return;
}
} // namespace TicTacToe
