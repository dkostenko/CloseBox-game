#include "level.h"

Level::Level()
{
    setCurrentMap();
}

bool Level::next()
{
    return setCurrentMap();
}

bool Level::setCurrentMap()
{
    inBig = -1;
    inSmall = -1;

    int blocs_count = 0;

    switch(++currentLevel)
    {
    case 1:
        rows = 3;
        cols = 3;
        time = 10;
        blocs_count = 3;
        blocs[0][0] = 1;    blocs[0][1] = 1;    blocs[0][2] = BALL;
        blocs[1][0] = 1;    blocs[1][1] = 0;    blocs[1][2] = SMALL_TOP;
        blocs[2][0] = 1;    blocs[2][1] = 2;    blocs[2][2] = BIG_LEFT;
        break;
    case 2:
        rows = 4;
        cols = 4;
        time = 80;
        blocs_count = 9;
        blocs[0][0] = 0;    blocs[0][1] = 3;    blocs[0][2] = BALL;
        blocs[1][0] = 1;    blocs[1][1] = 1;    blocs[1][2] = SMALL_LEFT;
        blocs[2][0] = 2;    blocs[2][1] = 0;    blocs[2][2] = BIG_BOTTOM;
        blocs[3][0] = 0;    blocs[3][1] = 1;    blocs[3][2] = BIG_BOTTOM;
        blocs[4][0] = 1;    blocs[4][1] = 2;    blocs[4][2] = SMALL_TOP;
        blocs[5][0] = 2;    blocs[5][1] = 1;    blocs[5][2] = SMALL_TOP;
        blocs[6][0] = 2;    blocs[6][1] = 2;    blocs[6][2] = SMALL_RIGHT;
        blocs[7][0] = 1;    blocs[7][1] = 3;    blocs[7][2] = BIG_LEFT;
        blocs[8][0] = 3;    blocs[8][1] = 2;    blocs[8][2] = BIG_TOP;
        break;
    case 6:
        rows = 3;
        cols = 3;
        time = 20;
        blocs_count = 3;
        blocs[0][0] = 1;    blocs[0][1] = 1;    blocs[0][2] = BALL;
        blocs[1][0] = 1;    blocs[1][1] = 2;    blocs[1][2] = SMALL_LEFT;
        blocs[2][0] = 1;    blocs[2][1] = 0;    blocs[2][2] = BIG_TOP;
        break;
    case 3:
        rows = 3;
        cols = 3;
        time = 40;
        blocs_count = 4;
        blocs[0][0] = 0;    blocs[0][1] = 0;    blocs[0][2] = BALL;
        blocs[1][0] = 2;    blocs[1][1] = 0;    blocs[1][2] = SMALL_TOP;
        blocs[2][0] = 1;    blocs[2][1] = 1;    blocs[2][2] = BIG_TOP;
        blocs[3][0] = 0;    blocs[3][1] = 2;    blocs[3][2] = BIG_LEFT;
        break;
    case 4:
        rows = 3;
        cols = 3;
        time = 60;
        blocs_count = 5;
        blocs[0][0] = 1;    blocs[0][1] = 1;    blocs[0][2] = BALL;
        blocs[1][0] = 1;    blocs[1][1] = 0;    blocs[1][2] = SMALL_RIGHT;
        blocs[2][0] = 1;    blocs[2][1] = 2;    blocs[2][2] = BIG_BOTTOM;
        blocs[3][0] = 0;    blocs[3][1] = 1;    blocs[3][2] = BIG_BOTTOM;
        blocs[3][0] = 2;    blocs[3][1] = 1;    blocs[3][2] = BIG_TOP;
        break;
    case 5:
        rows = 4;
        cols = 4;
        time = 80;
        blocs_count = 7;
        blocs[0][0] = 0;    blocs[0][1] = 2;    blocs[0][2] = BALL;
        blocs[1][0] = 1;    blocs[1][1] = 2;    blocs[1][2] = SMALL_RIGHT;
        blocs[2][0] = 0;    blocs[2][1] = 3;    blocs[2][2] = BIG_BOTTOM;
        blocs[3][0] = 3;    blocs[3][1] = 0;    blocs[3][2] = BIG_TOP;
        blocs[4][0] = 2;    blocs[4][1] = 1;    blocs[4][2] = SMALL_LEFT;
        blocs[5][0] = 1;    blocs[5][1] = 1;    blocs[5][2] = WALL;
        blocs[6][0] = 2;    blocs[6][1] = 2;    blocs[6][2] = WALL;
        break;
    case 10:
        rows = 5;
        cols = 5;
        time = 100;
        blocs_count = 11;
        blocs[0][0] = 4;    blocs[0][1] = 2;    blocs[0][2] = BALL;
        blocs[1][0] = 2;    blocs[1][1] = 1;    blocs[1][2] = SMALL_LEFT;
        blocs[2][0] = 2;    blocs[2][1] = 0;    blocs[2][2] = BIG_TOP;
        blocs[3][0] = 1;    blocs[3][1] = 2;    blocs[3][2] = WALL;
        blocs[4][0] = 1;    blocs[4][1] = 4;    blocs[4][2] = WALL;
        blocs[5][0] = 3;    blocs[5][1] = 1;    blocs[5][2] = WALL;
        blocs[6][0] = 1;    blocs[6][1] = 0;    blocs[6][2] = BIG_RIGHT;
        blocs[7][0] = 1;    blocs[7][1] = 1;    blocs[7][2] = SMALL_TOP;
        blocs[8][0] = 3;    blocs[8][1] = 2;    blocs[8][2] = BIG_BOTTOM;
        blocs[9][0] = 3;    blocs[9][1] = 3;    blocs[9][2] = WALL;
        blocs[10][0] = 3;   blocs[10][1] = 4;   blocs[10][2] = BIG_TOP;
        break;
    }
    for(int i = blocs_count; i < 20; ++i)
    {
        blocs[i][0] = -1;   blocs[i][1] = -1;   blocs[i][2] = 0;
    }

    if(blocs_count == 0) return false;
    return true;
}

bool Level::move(Direction direction)
{
    bool result = false;

    switch(direction)
    {
    case UP:
        if(chkDirection(blocs[0][0] - 1, blocs[0][1], UP))
        {
            blocs[0][0] = --blocs[0][0];

            if(inSmall != -1)
            {
                if(blocs[inSmall][2] == SMALL_TOP && inBig == -1)
                    inSmall = -1;
                else
                    blocs[inSmall][0] = blocs[0][0];
            }

            if(inBig != -1)
            {
                if(blocs[inBig][2] == BIG_TOP)
                    inBig = -1;
                else
                    blocs[inBig][0] = blocs[0][0];
            }

            result = true;
        }
        break;
    case RIGHT:
        if(chkDirection(blocs[0][0], blocs[0][1] + 1, RIGHT))
        {
            blocs[0][1] = ++blocs[0][1];

            if(inSmall != -1)
            {
                if(blocs[inSmall][2] == SMALL_RIGHT && inBig == -1)
                    inSmall = -1;
                else
                    blocs[inSmall][1] = blocs[0][1];
            }

            if(inBig != -1)
            {
                if(blocs[inBig][2] == BIG_RIGHT)
                    inBig = -1;
                else
                    blocs[inBig][1] = blocs[0][1];
            }

            result = true;
        }
        break;
    case DOWN:
        if(chkDirection(blocs[0][0] + 1, blocs[0][1], DOWN))
        {
            blocs[0][0] = ++blocs[0][0];

            if(inSmall != -1)
            {
                if(blocs[inSmall][2] == SMALL_BOTTOM && inBig == -1)
                    inSmall = -1;
                else
                    blocs[inSmall][0] = blocs[0][0];
            }

            if(inBig != -1)
            {
                if(blocs[inBig][2] == BIG_BOTTOM)
                    inBig = -1;
                else
                    blocs[inBig][0] = blocs[0][0];
            }

            result = true;
        }
        break;
    case LEFT:
        if(chkDirection(blocs[0][0], blocs[0][1] - 1, LEFT))
        {
            blocs[0][1] = --blocs[0][1];

            if(inSmall != -1)
            {
                if(blocs[inSmall][2] == SMALL_LEFT && inBig == -1)
                    inSmall = -1;
                else
                    blocs[inSmall][1] = blocs[0][1];
            }

            if(inBig != -1)
            {
                if(blocs[inBig][2] == BIG_LEFT)
                    inBig = -1;
                else
                    blocs[inBig][1] = blocs[0][1];
            }

            result = true;
        }
        break;
    }

    return result;
}

bool Level::chkDirection(int newRow, int newCol, Direction direction)
{
    // check leaves the map
    if(newRow >= rows || newCol >= cols || newRow < 0 || newCol < 0)
        return false;

    for(int i = 0; i < 20; ++i)
    {
        // check for collisions with the wall
        if(blocs[i][0] == newRow && blocs[i][1] == newCol)
        {
            if(blocs[i][2] == WALL)
                return false;

            switch(direction)
            {
            case UP:
                if(blocs[i][2] != BIG_BOTTOM && blocs[i][2] != SMALL_BOTTOM)
                    return false;
                if(inBig != -1 && blocs[inBig][2] != BIG_TOP)
                    return false;
                if(inSmall != -1 && blocs[i][2] != BIG_BOTTOM && blocs[inSmall][2] != SMALL_TOP)
                    return false;
                break;
            case RIGHT:
                if(blocs[i][2] != BIG_LEFT && blocs[i][2] != SMALL_LEFT)
                    return false;
                if(inBig != -1 && blocs[inBig][2] != BIG_RIGHT)
                    return false;
                if(inSmall != -1 && blocs[i][2] != BIG_LEFT && blocs[inSmall][2] != SMALL_RIGHT)
                    return false;
                break;
            case DOWN:
                if(blocs[i][2] != BIG_TOP && blocs[i][2] != SMALL_TOP)
                    return false;
                if(inBig != -1 && blocs[inBig][2] != BIG_BOTTOM)
                    return false;
                if(inSmall != -1 && blocs[i][2] != BIG_TOP && blocs[inSmall][2] != SMALL_BOTTOM)
                    return false;
                break;
            case LEFT:
                if(blocs[i][2] != BIG_RIGHT && blocs[i][2] != SMALL_RIGHT)
                    return false;
                if(inBig != -1 && blocs[inBig][2] != BIG_LEFT)
                    return false;
                if(inSmall != -1 && blocs[i][2] != BIG_RIGHT && blocs[inSmall][2] != SMALL_LEFT)
                    return false;
                break;
            }

            if(blocs[i][2] == BIG_TOP || blocs[i][2] == BIG_RIGHT || blocs[i][2] == BIG_BOTTOM || blocs[i][2] == BIG_LEFT)
                inBig = i;

            if(blocs[i][2] == SMALL_TOP || blocs[i][2] == SMALL_RIGHT || blocs[i][2] == SMALL_BOTTOM || blocs[i][2] == SMALL_LEFT)
                inSmall = i;
        }
    }
    return true;
}

bool Level::isFinished()
{
    if(blocs[0][0] == blocs[1][0] && blocs[0][0] == blocs[2][0] &&
       blocs[0][1] == blocs[1][1] && blocs[0][1] == blocs[2][1])
        return true;

    return false;
}

QString Level::getTimerText()
{
    QString q;
    q.setNum(--time);
    return q + " sec. left";
}

QString Level::getCurrentLevelText()
{
    QString q;
    q.setNum(currentLevel);
    return "Level: " + q;
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

int Level::getTime()
{
    return time;
}
