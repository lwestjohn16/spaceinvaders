#ifndef PLAYER_H
#define PLAYER_H
#include <QPixmap>

class player
{
private:
    int xcoord, ycoord;
public:
    player();
    void moveRight();
    void moveLeft();
    int getX();
    int getY();
};

#endif // PLAYER_H
