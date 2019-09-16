#pragma once
#include "ofMain.h"
#include "Ball.h"

class Endpoint {
private:
	int adjTile; //The tile number the endpoint will be adjacent to
	int orientation;
	ofVec2f position;
	ofImage end;

public:
	void setAdj(int x);
	int getAdj();
	bool collision(Ball b);
	void setup();
	void draw(float width, float height);
	void setOrientation(int x);
    void setPosition(ofVec2f pos, float dim);
    ofVec2f getPosition();
    
};
