#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtCore>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QtGui>
#include <level.h>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    QTimer *timer;

public slots:
    void Tic();

private slots:
    void on_startGame_clicked();

private:

    enum State { INSTRUCTION, RUN, PAUSED, GAME_FINISHED, GAME_LOST };
    State currentState;
    Level * lvl;
    Ui::Dialog *ui;
    QGraphicsScene *scene;
    QGraphicsRectItem *rectangle;
    void changeState(State state);
    void drawGrid(int rows, int cols);
    void drawBigBox(int row, int col, int type, bool main);
    void drawSmallBox(int row, int col, int type, bool main);
    void drawBall(int row, int col);
    void drawWall(int row, int col);
    void keyPressEvent(QKeyEvent *e);
    void paintEvent(QPaintEvent *e);
};

#endif // DIALOG_H
