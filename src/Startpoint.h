#pragma once
#include "ofMain.h"


#ifndef Startpoint_h
#define Startpoint_h


#endif /* Startpoint_h */


class Startpoint {
private:
    
    
    ofVec2f position;
    ofImage start;
    
    
public:
    
    ofVec2f getPosition();
    
    void setup();
    void draw(float w, float h);
    
    void setPositionTop(ofVec2f pos, int mult, float dim, int size);
    void setPositionRight(ofVec2f pos, int mult, float dim, int size);
    void setPositionLeft(ofVec2f pos, int mult, float dim, int size);
    void setPositionBottom(ofVec2f pos, int mult, float dim, int size);
};
