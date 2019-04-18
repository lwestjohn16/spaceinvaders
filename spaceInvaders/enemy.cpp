#include "enemy.h"

enemy::enemy(int x, int y)
{
    xcoord = x;
    ycoord = y;
    rect = new QRect(x, y, 50, 50);
}
