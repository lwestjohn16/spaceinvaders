#include "enemy.h"

enemy::enemy(){

}

enemy::enemy(int x, int y){
    xcoord = x;
    ycoord = y;
    isDead = false;
}

void enemy::setValue(int val){
    value = val;
}

int enemy::getX(){
    return xcoord;
}

int enemy::getY(){
    return ycoord;
}

void enemy::moveX(int x){
    xcoord += x;
}

void enemy::moveY(int y){
    ycoord += y;
}

bool enemy::getDead(){
    return isDead;
}

void enemy::setDead(bool a){
    isDead = a;
}

int enemy::getValue(){
    return value;
}
