#ifndef BUNKER_H
#define BUNKER_H
#include <QRect>

class bunker
{
private:
    int health = 3;
    int xcoord, ycoord;
public:
    bunker();
    bunker(int x, int y);
    QRect *rect;
    int getHealth();
    void setY(int y);
    void setX(int x);
    void setHealth(int h);
};

#endif // BUNKER_H
