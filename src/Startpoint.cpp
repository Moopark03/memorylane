#include "Startpoint.h"


ofVec2f Startpoint::getPosition(){
    return position;
}


void Startpoint::setup(){
    start.load("images/end.png");
    ofColor red(255, 0, 0);
    start.setColor(red);
}

void Startpoint::draw(float w, float h){
    start.draw(position, w, h);
}

void Startpoint::setPositionTop(ofVec2f pos, int mult, float dim, int size){
    position.y = pos.y - dim;
    position.x = pos.x + (dim * mult);
}

void Startpoint::setPositionRight(ofVec2f pos, int mult, float dim, int size){
    position.x = pos.x + (dim * size);
    position.y = pos.y + (dim * mult);
}

void Startpoint::setPositionLeft(ofVec2f pos, int mult, float dim, int size){
    position.x = pos.x - dim;
    position.y = pos.y + (dim * mult);
}

void Startpoint::setPositionBottom(ofVec2f pos, int mult, float dim, int size){
    position.y = pos.y + (dim * size);
    position.x = pos.x + (dim * mult);
}


//Possible solutions:
/**
1. Keep track of all edges during board build and pass it onto each startpoint to draw
2. Set all the startpoint positions while making board


 **/
