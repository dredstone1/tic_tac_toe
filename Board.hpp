enum cell { X = 'X', O = 'O', EMPTY = ' ' };

class Board {
public:
  Board();
  void draw();
  void set(int x, int y, cell c);
  cell get(int x, int y);
  bool isFull();
  bool isWinner(char c);

private:
  cell board[3][3];
};

