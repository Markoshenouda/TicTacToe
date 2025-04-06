#include "GameLogic.h"
#include <iostream>

TicTacToe::TicTacToe() {
    board = std::vector<std::vector<char>>(SIZE, std::vector<char>(SIZE, ' '));
}

void TicTacToe::displayBoard() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            std::cout << board[i][j];
            if (j < SIZE - 1) std::cout << " | ";
        }
        std::cout << std::endl;
        if (i < SIZE - 1) std::cout << "---------" << std::endl;
    }
}

bool TicTacToe::makeMove(int row, int col, char player) {
    if (board[row][col] == ' ') {
        board[row][col] = player;
        return true;
    }
    return false;
}

bool TicTacToe::checkWin(char player) {
    for (int i = 0; i < SIZE; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    return false;
}

bool TicTacToe::isBoardFull() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

void TicTacToe::resetGame() {
    board = std::vector<std::vector<char>>(SIZE, std::vector<char>(SIZE, ' '));
}
