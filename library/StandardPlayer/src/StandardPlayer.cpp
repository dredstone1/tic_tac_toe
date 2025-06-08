#include "../include/StandardPlayer/StandardPlayer.hpp"
#include <iostream>

StandardPlayer::StandardPlayer() {}

int StandardPlayer::getMove() {
	std::cout << (char)getPlayerMode() << ": Enter your move: ";
	int move;
	std::cin >> move;
	return move;
}

void StandardPlayer::UserLost() {
	std::cout << (char)getPlayerMode() << ": You lost!" << std::endl;
}

void StandardPlayer::UserWin() {
	std::cout << (char)getPlayerMode() << ": You win!" << std::endl;
	std::cout << (char)getPlayerMode() << ": You have " << getScore() << " points" << std::endl;
}

void StandardPlayer::UserDraw() {
	std::cout << (char)getPlayerMode() << ": Draw!" << std::endl;
}
