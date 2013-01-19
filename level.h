#ifndef LEVEL_H
#define LEVEL_H

class Level
{
public:
    Level(int level);
    enum Direction { UP, RIGHT, DOWN, LEFT };
    int getBloc(int row, int col);
    void setBloc(int row, int col, int value);
    int getRows();
    int getCols();
    int getSteps();
    bool move(Direction direction);

private:
    enum BlocTypes {BALL, WALL,
                    RED_TOP, RED_RIGHT, RED_BOTTOM, RED_LEFT,
                    BLUE_TOP, BLUE_RIGHT, BLUE_BOTTOM, BLUE_LEFT,
                    BIG_TOP, BIG_RIGHT, BIG_BOTTOM, BIG_LEFT,
                    SMALL_TOP, SMALL_RIGHT, SMALL_BOTTOM, SMALL_LEFT };

    int rows;
    int cols;
    int blocs[20][3];
    int steps;

    bool chkDirection(int newRow, int newCol);
};

#endif // LEVEL_H
