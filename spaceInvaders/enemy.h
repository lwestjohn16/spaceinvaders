#ifndef ENEMY_H
#define ENEMY_H
#include <QPixmap>

class enemy
{
private:
    int value;
    int xcoord, ycoord;
    bool isDead;
public:
    enemy();
    enemy(int x, int y);
    void setValue(int val);
    int getX();
    int getY();
    void moveX(int x);
    void moveY(int y);
    bool getDead();
    void setDead(bool a);
    int getValue();
};

#endif // ENEMY_H
