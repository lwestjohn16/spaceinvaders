#ifndef PLAYER_H
#define PLAYER_H
#include <QRect>

class player
{
private:
    QRect rect;
    int xcoord, ycoord;
public:
    player();
    void moveRight();
    void moveLeft();
};

#endif // PLAYER_H
