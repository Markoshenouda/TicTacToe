#include "AI.h"
#include <limits.h>
#include <algorithm>

AI::AI() {}

int AI::evaluateBoard(TicTacToe &game) {
    if (game.checkWin('O')) return 10;
    if (game.checkWin('X')) return -10;
    return 0;
}

int AI::minimax(TicTacToe &game, int depth, bool isMaximizingPlayer) {
    int score = evaluateBoard(game);
    if (score == 10 || score == -10) return score;
    if (game.isBoardFull()) return 0;

    if (isMaximizingPlayer) {
        int best = INT_MIN;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (game.makeMove(i, j, 'O')) {
                    best = std::max(best, minimax(game, depth + 1, !isMaximizingPlayer));
                    game.resetGame();
                }
            }
        }
        return best;
    } else {
        int best = INT_MAX;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (game.makeMove(i, j, 'X')) {
                    best = std::min(best, minimax(game, depth + 1, !isMaximizingPlayer));
                    game.resetGame();
                }
            }
        }
        return best;
    }
}

int AI::bestMove(TicTacToe &game) {
    int bestVal = INT_MIN;
    int row = -1, col = -1;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (game.makeMove(i, j, 'O')) {
                int moveVal = minimax(game, 0, false);
                game.resetGame();
                if (moveVal > bestVal) {
                    row = i;
                    col = j;
                    bestVal = moveVal;
                }
            }
        }
    }
    return row * 3 + col;
}
