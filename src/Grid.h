#pragma once
#include "ofMain.h"

class Grid{
private:

	int piece; //The vector<Grid>'s index will be to reference how many pieces to lay down based on size.
	ofVec2f position;
	int x;
	int y;
	ofImage floor;		   //Piece will be 0, 1, 2 for floor, /, 
	ofImage bump1;
	ofImage bump2;


public:
	int getX();
	int getY();
	int getPiece();
	ofVec2f getPosition();

	void setPosition(int x, int y);
	void setX(int in);
	void setY(int in);
	void setPiece(int in);
	void setup();
	void draw(float w, float h);

};


