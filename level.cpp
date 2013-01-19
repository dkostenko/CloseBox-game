#include "level.h"

Level::Level(int level)
{
    switch(level)
    {
    case 10:
        steps = 50;
        rows = 5;
        cols = 5;
        blocs[0][0] = 4;    blocs[0][1] = 2;    blocs[0][2] = BALL;
        blocs[1][0] = 2;    blocs[1][1] = 1;    blocs[1][2] = RED_LEFT;
        blocs[2][0] = 2;    blocs[2][1] = 0;    blocs[2][2] = BLUE_TOP;
        blocs[3][0] = 1;    blocs[3][1] = 2;    blocs[3][2] = WALL;
        blocs[4][0] = 1;    blocs[4][1] = 4;    blocs[4][2] = WALL;
        blocs[5][0] = 3;    blocs[5][1] = 1;    blocs[5][2] = WALL;
        blocs[6][0] = 1;    blocs[6][1] = 0;    blocs[6][2] = BIG_RIGHT;
        blocs[7][0] = 1;    blocs[7][1] = 1;    blocs[7][2] = SMALL_TOP;
        blocs[8][0] = 3;    blocs[8][1] = 2;    blocs[8][2] = BIG_BOTTOM;
        blocs[9][0] = 3;    blocs[10][1] = 3;   blocs[9][2] = WALL;
        blocs[10][0] = 3;   blocs[10][1] = 4;   blocs[10][2] = BIG_TOP;
        break;
    }
}

bool Level::move(Direction direction)
{
    switch(direction)
    {
    case UP:
        if(chkDirection(blocs[0][0] - 1, blocs[0][1]))
            blocs[0][0] = --blocs[0][0];
        return true;
    case RIGHT:
        if(chkDirection(blocs[0][0], blocs[0][1] + 1))
            blocs[0][1] = ++blocs[0][1];
        return true;
    case DOWN:
        if(chkDirection(blocs[0][0] + 1, blocs[0][1]))
            blocs[0][0] = ++blocs[0][0];
        return true;
    case LEFT:
        if(chkDirection(blocs[0][0], blocs[0][1] - 1))
            blocs[0][1] = --blocs[0][1];
        return true;
    }

    return false;
}

bool Level::chkDirection(int newRow, int newCol)
{
    // проверка выхода а предела карты
    if(newRow >= rows || newCol >= cols || newRow < 0 || newCol < 0)
        return false;

    // проверка столкновения со стеной
    for(int i = 0; i < 20; ++i)
    {
        if(blocs[i][0] == newRow && blocs[i][1] == newCol && blocs[i][2] == WALL)
            return false;
    }
    return true;
}


// Properties
int Level::getBloc(int row, int col)
{
    return blocs[row][col];
}

void Level::setBloc(int row, int col, int value)
{
    blocs[row][col] = value;
}

int Level::getCols()
{
    return cols;
}

int Level::getRows()
{
    return rows;
}

int Level::getSteps()
{
    return steps;
}
