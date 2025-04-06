#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <vector>

class TicTacToe {
public:
    TicTacToe();
    void displayBoard();
    bool makeMove(int row, int col, char player);
    bool checkWin(char player);
    bool isBoardFull();
    void resetGame();

private:
    std::vector<std::vector<char>> board;
    const int SIZE = 3;
};

#endif // GAMELOGIC_H
