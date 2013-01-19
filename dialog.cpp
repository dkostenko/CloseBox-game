#include "dialog.h"
#include "ui_dialog.h"
#include "scene.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    lvl = new Level(10);
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    ui->currentLvl->setText("Уровень: 10");

    ui->leftSteps->setText("Осталось шагов: " + lvl->getSteps());

    qDebug() << lvl->getCols();

    ui->graphicsView->setEnabled(false);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::drawGrid(int rows, int cols)
{
    QPen blackpen(Qt::black);

    // вертикальные линии
    for(int i = 0; i <= cols; ++i)
        scene->addLine(i*100, 0, i*100, rows*100, blackpen);

    // горизонтальные линии
    for(int i = 0; i <= rows; ++i)
        scene->addLine(0, i*100, cols*100, i*100, blackpen);
}

void Dialog::drawBall(int row, int col)
{
    rectangle = scene->addRect(col * 100 + 35, row * 100 + 35, 30, 30, QPen(Qt::black), QBrush(Qt::black));
}

void Dialog::drawBigBox(int row, int col, int type, bool main)
{
    QPen pen;

    if(main)
        pen.setColor(Qt::blue);
    else
        pen.setColor(Qt::black);

    pen.setWidth(6);

    if(type != 1)
        scene->addLine(col * 100 + 10, row * 100 + 10, col * 100 + 90, row * 100 + 10, pen);

    if(type != 2)
        scene->addLine(col * 100 + 90, row * 100 + 90, col * 100 + 90, row * 100 + 10, pen);

    if(type != 3)
        scene->addLine(col * 100 + 90, row * 100 + 90, col * 100 + 10, row * 100 + 90, pen);

    if(type != 4)
        scene->addLine(col * 100 + 10, row * 100 + 10, col * 100 + 10, row * 100 + 90, pen);
}

void Dialog::drawSmallBox(int row, int col, int type, bool main)
{
    QPen pen;

    if(main)
        pen.setColor(Qt::red);
    else
        pen.setColor(Qt::black);

    pen.setWidth(3);

    if(type != 1)
        scene->addLine(col * 100 + 20, row * 100 + 20, col * 100 + 80, row * 100 + 20, pen);

    if(type != 2)
        scene->addLine(col * 100 + 80, row * 100 + 80, col * 100 + 80, row * 100 + 20, pen);

    if(type != 3)
        scene->addLine(col * 100 + 80, row * 100 + 80, col * 100 + 20, row * 100 + 80, pen);

    if(type != 4)
        scene->addLine(col * 100 + 20, row * 100 + 20, col * 100 + 20, row * 100 + 80, pen);
}



void Dialog::drawWall(int row, int col)
{
    rectangle = scene->addRect(col * 100, row * 100, 100, 100, QPen(Qt::black), QBrush(Qt::black));
}

void Dialog::keyPressEvent(QKeyEvent *e)
{
    bool isMoved = false;

    switch(e->key())
    {
    case Qt::Key_Up:
        isMoved = lvl->move(lvl->UP);
        break;
    case Qt::Key_Right:
        isMoved = lvl->move(lvl->RIGHT);
        break;
    case Qt::Key_Down:
        isMoved = lvl->move(lvl->DOWN);
        break;
    case Qt::Key_Left:
        isMoved = lvl->move(lvl->LEFT);
        break;
    }

    this->repaint();
}

void Dialog::paintEvent(QPaintEvent *e)
{
    scene->clear();

    for(int i = 0; i < 11; ++i)
    {
        switch(lvl->getBloc(i, 2))
        {
        case BALL:
            drawBall(lvl->getBloc(i, 0), lvl->getBloc(i, 1));
            break;
        case WALL:
            drawWall(lvl->getBloc(i, 0), lvl->getBloc(i, 1));
            break;

        case RED_TOP:
            drawSmallBox(lvl->getBloc(i, 0), lvl->getBloc(i, 1), 1, true);
            break;
        case RED_RIGHT:
            drawSmallBox(lvl->getBloc(i, 0), lvl->getBloc(i, 1), 2, true);
            break;
        case RED_BOTTOM:
            drawSmallBox(lvl->getBloc(i, 0), lvl->getBloc(i, 1), 3, true);
            break;
        case RED_LEFT:
            drawSmallBox(lvl->getBloc(i, 0), lvl->getBloc(i, 1), 4, true);
            break;

        case BLUE_TOP:
            drawBigBox(lvl->getBloc(i, 0), lvl->getBloc(i, 1), 1, true);
            break;
        case BLUE_RIGHT:
            drawBigBox(lvl->getBloc(i, 0), lvl->getBloc(i, 1), 2, true);
            break;
        case BLUE_BOTTOM:
            drawBigBox(lvl->getBloc(i, 0), lvl->getBloc(i, 1), 3, true);
            break;
        case BLUE_LEFT:
            drawBigBox(lvl->getBloc(i, 0), lvl->getBloc(i, 1), 4, true);
            break;

        case BIG_TOP:
            drawBigBox(lvl->getBloc(i, 0), lvl->getBloc(i, 1), 1, false);
            break;
        case BIG_RIGHT:
            drawBigBox(lvl->getBloc(i, 0), lvl->getBloc(i, 1), 2, false);
            break;
        case BIG_BOTTOM:
            drawBigBox(lvl->getBloc(i, 0), lvl->getBloc(i, 1), 3, false);
            break;
        case BIG_LEFT:
            drawBigBox(lvl->getBloc(i, 0), lvl->getBloc(i, 1), 4, false);
            break;

        case SMALL_TOP:
            drawSmallBox(lvl->getBloc(i, 0), lvl->getBloc(i, 1), 1, false);
            break;
        case SMALL_RIGHT:
            drawSmallBox(lvl->getBloc(i, 0), lvl->getBloc(i, 1), 2, false);
            break;
        case SMALL_BOTTOM:
            drawSmallBox(lvl->getBloc(i, 0), lvl->getBloc(i, 1), 3, false);
            break;
        case SMALL_LEFT:
            drawSmallBox(lvl->getBloc(i, 0), lvl->getBloc(i, 1), 4, false);
            break;
        }
    }

    drawGrid(5, 5);
}
