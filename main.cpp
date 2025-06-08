#include <AiPlayer.hpp>
#include <StandardPlayer/StandardPlayer.hpp>
#include <TicTacToe/game.hpp>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
	StandardPlayer StandardPlayer1;
	std::cout << "Start Game" << std::endl;

	// if (argc > 1 && argv[1][0] == '2') {
	//           std::cout << "2 Players Game" << std::endl;
	// 	StandardPlayer StandardPlayer2;
	// 	Game game(&StandardPlayer1, &StandardPlayer2);
	// 	game.run();
	// 	return 0;
	// }

	std::cout << "AI Game" << std::endl;

    std::string config_file_name("config.json");

	AiPlayer aiPlayer(config_file_name);

    TicTacToe::Game game(&StandardPlayer1, &aiPlayer);
	// Game game(&aiPlayer, &StandardPlayer1);

	game.run();
	return 0;
}
