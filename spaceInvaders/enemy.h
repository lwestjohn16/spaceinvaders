#ifndef ENEMY_H
#define ENEMY_H
#include <QRect>

class enemy
{
private:
    int value;
    QRect rect;
    int xcoord, ycoord, xspeed, yspeed;
    bool isDead;
public:
    enemy(int x, int y);
};

#endif // ENEMY_H
