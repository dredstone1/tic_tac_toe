#include "../include/StandardPlayer/StandardPlayer.hpp"
#include <iostream>

using namespace std;

StandardPlayer::StandardPlayer() {}

int StandardPlayer::getMove() {
	cout << (char)getPlayerMode() << ": Enter your move: ";
	int move;
	cin >> move;
	return move;
}

void StandardPlayer::UserLost() {
	cout << (char)getPlayerMode() << ": You lost!" << endl;
}

void StandardPlayer::UserWin() {
	cout << (char)getPlayerMode() << ": You win!" << endl;
	cout << (char)getPlayerMode() << ": You have " << getScore() << " points"
	     << endl;
}

void StandardPlayer::UserDraw() {
	cout << (char)getPlayerMode() << ": Draw!" << endl;
}
