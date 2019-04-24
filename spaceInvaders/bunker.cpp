#include "bunker.h"

bunker::bunker(){

}

bunker::bunker(int x, int y){
    xcoord = x;
    ycoord = y;
    rect = new QRect(xcoord, ycoord, 50, 50);
}

int bunker::getHealth(){
    return health;
}

void bunker::setX(int x){
    xcoord = x;
}

void bunker::setY(int y){
    ycoord = y;
}

void bunker::setHealth(int h){
    health += h;
}
