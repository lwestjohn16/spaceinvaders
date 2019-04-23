#include "player.h"

player::player()
{

}

void player::moveLeft()
{
    xcoord -= 10;
}

void player::moveRight()
{
    xcoord += 10;
}
