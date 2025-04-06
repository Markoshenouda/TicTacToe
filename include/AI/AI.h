#ifndef AI_H
#define AI_H

#include "GameLogic.h"

class AI {
public:
    AI();
    int minimax(TicTacToe &game, int depth, bool isMaximizingPlayer);
    int bestMove(TicTacToe &game);

private:
    int evaluateBoard(TicTacToe &game);
};

#endif // AI_H
