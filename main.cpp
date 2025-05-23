#include <AiPlayer/AiModel.hpp>
#include <AiPlayer/AiPlayer.hpp>
#include <StandardPlayer/StandardPlayer.hpp>
#include <TicTacToe/game.hpp>
#include <Trainer/trainer.hpp>
#include <iostream>

using namespace TicTacToe;
using namespace std;

int main(int argc, char *argv[]) {
	if (argc > 1) {
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

		AiModel model;
		char *arg = argv[1];
		while (*(arg) != '\0') {
			switch (*arg) {
			case 'l':
				model.load("model1");
				break;
			case 's':
				model.save("model1");
				break;
			case 't':
				int batch_size = 64, batch_count = 10000;

				double learning_rate = 0.000001;

				Trainer trainer(
				    "database",
				    &model,
				    batch_size,
				    batch_count,
				    learning_rate);

				trainer.train();
				model.save("model1");
				break;
			}
			arg++;
		}

		AiPlayer aiPlayer(&model);

		Game game(&StandardPlayer1, &aiPlayer);
		// Game game(&aiPlayer, &StandardPlayer1);
		game.run();
		return 0;
	}

	cout << "Need at least 1 input!" << endl;
	return 1;
}
