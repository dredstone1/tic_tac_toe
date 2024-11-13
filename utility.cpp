#include "utility.hpp"
#include <stdexcept>

// Function to get the position (row, column) from a number 1 to 9
std::pair<int, int> getPosition(int number) {
    if (number < 1 || number > 9) {
        throw std::out_of_range("Number must be between 1 and 9");
    }

    int row = (number - 1) / 3;
    int col = (number - 1) % 3;
    return std::make_pair(row, col);
}
