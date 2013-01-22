#ifndef LEVEL_H
#define LEVEL_H

#include <QtCore>

class Level
{
public:
    Level();
    enum Direction { UP, RIGHT, DOWN, LEFT };
    enum BlocTypes {BALL, WALL,
                    BIG_TOP, BIG_RIGHT, BIG_BOTTOM, BIG_LEFT,
                    SMALL_TOP, SMALL_RIGHT, SMALL_BOTTOM, SMALL_LEFT };
    int getBloc(int row, int col);
    void setBloc(int row, int col, int value);
    int getRows();
    int getCols();
    int getTime();
    QString getCurrentLevelText();
    QString getTimerText();
    bool move(Direction direction);
    bool isFinished();
    bool next();

private:
    int currentLevel;
    int rows;
    int cols;
    int blocs[20][3];
    int inBig;
    int inSmall;
    int time;
    bool setCurrentMap();

    bool chkDirection(int newRow, int newCol, Direction direction);
};

#endif // LEVEL_H
