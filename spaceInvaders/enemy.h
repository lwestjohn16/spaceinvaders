#ifndef ENEMY_H
#define ENEMY_H
#include <QRect>

class enemy
{
private:
    int value;
    QRect rect;
    int xcoord, ycoord, xspeed, yspeed;
public:
    enemy();
};

#endif // ENEMY_H
