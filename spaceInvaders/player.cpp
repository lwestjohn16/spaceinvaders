#include "player.h"

player::player()
{
    ycoord = 750;
    xcoord = 500;
}

void player::moveLeft()
{
    xcoord -= 10;
}

void player::moveRight()
{
    xcoord += 10;
}

int player::getX()
{
    return xcoord;
}

int player::getY()
{
    return ycoord;
}
