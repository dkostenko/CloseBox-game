#include "dialog.h"
#include "ui_dialog.h"
#include "scene.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    currentLvl = 1;
    lvl = new Level(currentLvl);
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);

    ui->currentLvl->setText("Уровень: 10");
    ui->leftSteps->setText("Осталось шагов: " + lvl->getSteps());

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

    if(type != 2)
        scene->addLine(col * 100 + 10, row * 100 + 10, col * 100 + 90, row * 100 + 10, pen);

    if(type != 3)
        scene->addLine(col * 100 + 90, row * 100 + 90, col * 100 + 90, row * 100 + 10, pen);

    if(type != 4)
        scene->addLine(col * 100 + 90, row * 100 + 90, col * 100 + 10, row * 100 + 90, pen);

    if(type != 5)
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

    if(type != 6)
        scene->addLine(col * 100 + 20, row * 100 + 20, col * 100 + 80, row * 100 + 20, pen);

    if(type != 7)
        scene->addLine(col * 100 + 80, row * 100 + 80, col * 100 + 80, row * 100 + 20, pen);

    if(type != 8)
        scene->addLine(col * 100 + 80, row * 100 + 80, col * 100 + 20, row * 100 + 80, pen);

    if(type != 9)
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

    if(isMoved)
    {
        if(lvl->isFinished())
        {
            qDebug() << "ВЫИГРАЛ!";
            lvl = new Level(++currentLvl);
        }
        this->repaint();
    }
}

void Dialog::paintEvent(QPaintEvent *e)
{
    scene->clear();

    drawBall(lvl->getBloc(0, 0), lvl->getBloc(0, 1));
    drawSmallBox(lvl->getBloc(1, 0), lvl->getBloc(1, 1), lvl->getBloc(1, 2), true);
    drawBigBox(lvl->getBloc(2, 0), lvl->getBloc(2, 1), lvl->getBloc(2, 2), true);

    for(int i = 3; i < 12; ++i)
    {
        if(lvl->getBloc(i, 2) == lvl->WALL)
        {
            drawWall(lvl->getBloc(i, 0), lvl->getBloc(i, 1));
            continue;
        }

        if(lvl->getBloc(i, 2) == lvl->BIG_TOP || lvl->getBloc(i, 2) == lvl->BIG_RIGHT || lvl->getBloc(i, 2) == lvl->BIG_BOTTOM || lvl->getBloc(i, 2) == lvl->BIG_LEFT)
        {
            drawBigBox(lvl->getBloc(i, 0), lvl->getBloc(i, 1), lvl->getBloc(i, 2), false);
            continue;
        }

        if(lvl->getBloc(i, 2) == lvl->SMALL_TOP || lvl->getBloc(i, 2) == lvl->SMALL_RIGHT || lvl->getBloc(i, 2) == lvl->SMALL_BOTTOM || lvl->getBloc(i, 2) == lvl->SMALL_LEFT)
        {
            drawSmallBox(lvl->getBloc(i, 0), lvl->getBloc(i, 1), lvl->getBloc(i, 2), false);
            continue;
        }
    }

    drawGrid(lvl->getRows(), lvl->getCols());
}
