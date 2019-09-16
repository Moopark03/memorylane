#pragma once
#include "ofMain.h"
#include "Grid.h"
#include "Endpoint.h"
#include "Startpoint.h"

class Board {//Board class makes the board that increases in size
private:
	//Variables
	int size = 5;
	int bumpSize = size;
	int bumpOrient;
	vector<Grid> board; //throw in the cubes to be made all with positions
	vector<int> offBoard;
    vector<Startpoint> start;
	float width = ofGetWindowWidth() / 12;
	float height = width;
	int random;

	
	//Variables for interaction objects
	Endpoint endPoint;
	Grid temp; //to add
    Startpoint startPoint;

	int selectEnd(int random);
	void buildBumpers(int index);
	int findIndex(int x, int y);
	void setNewOrient(int piece);
	void randomBump();
	void blockList(); //This should be the method that adds all indices to be blocked. Nothing gets blocked so far
	bool checkOffBoard(int newIndex);
	int fixBlock(int x, int y);
    void setGridPos();

public:
	void draw();
	void setSize(int x);
	void buildBoard();
	void setup();
    void drawBlank();


};
