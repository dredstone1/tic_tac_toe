#include "Board.hpp"
#include <iostream>

using namespace std;

int main() {
  Board b;
  b.set(1, 1, X);
  b.draw();
  return 0;
}
