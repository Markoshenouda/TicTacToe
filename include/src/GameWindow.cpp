#include "GameWindow.h"
#include "GameLogic.h"
#include "AI.h"
#include <QMessageBox>

GameWindow::GameWindow() {
    QGridLayout *layout = new QGridLayout();
    
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            buttons[i][j] = new QPushButton(" ");
            layout->addWidget(buttons[i][j], i, j);
            connect(buttons[i][j], &QPushButton::clicked, [this, i, j] { onButtonClicked(i, j); });
        }
    }
    
    setLayout(layout);
    setWindowTitle("Tic Tac Toe");
}

void GameWindow::onButtonClicked(int row, int col) {
    if (game.makeMove(row, col, 'X')) {
        buttons[row][col]->setText("X");
        if (game.checkWin('X')) {
            QMessageBox::information(this, "Game Over", "You win!");
        } else if (game.isBoardFull()) {
            QMessageBox::information(this, "Game Over", "It's a tie!");
        } else {
            int move = ai.bestMove(game);
            int aiRow = move / 3;
            int aiCol = move % 3;
            game.makeMove(aiRow, aiCol, 'O');
            buttons[aiRow][aiCol]->setText("O");
            if (game.checkWin('O')) {
                QMessageBox::information(this, "Game Over", "AI wins!");
            }
        }
    }
}
