#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtCore>
#include <QGraphicsScene>
#include <QGraphicsItem>
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

private:
    enum BlocTypes { BALL, WALL,
                 RED_TOP, RED_RIGHT, RED_BOTTOM, RED_LEFT,
                 BLUE_TOP, BLUE_RIGHT, BLUE_BOTTOM, BLUE_LEFT,
                 BIG_TOP, BIG_RIGHT, BIG_BOTTOM, BIG_LEFT,
                 SMALL_TOP, SMALL_RIGHT, SMALL_BOTTOM, SMALL_LEFT };

    Level * lvl;

    Ui::Dialog *ui;
    QGraphicsScene *scene;
    QGraphicsRectItem *rectangle;
    void drawGrid(int rows, int cols);
    void drawBigBox(int row, int col, int type, bool main);
    void drawSmallBox(int row, int col, int type, bool main);
    void drawBall(int row, int col);
    void drawWall(int row, int col);
    void keyPressEvent(QKeyEvent *e);
    void paintEvent(QPaintEvent *e);
};

#endif // DIALOG_H
