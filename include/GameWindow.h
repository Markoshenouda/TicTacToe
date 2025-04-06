#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QtWidgets>

class GameWindow : public QWidget {
public:
    GameWindow();

private:
    QPushButton *buttons[3][3];
    TicTacToe game;
    AI ai;
    void onButtonClicked(int row, int col);
};

#endif // GAMEWINDOW_H
