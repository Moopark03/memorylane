#include "Grid.h"



int Grid::getX() {
	return x;
}

int Grid::getY() {
	return y;
}

int Grid::getPiece() {
	return piece;
}

ofVec2f Grid::getPosition() {
	return position;
}

void Grid::setPosition(int x, int y) {
	position.set(x, y);
}

void Grid::setX(int in) {
	x = in;
}

void Grid::setY(int in) {
	y = in;
}

void Grid::setPiece(int in) {
	piece = in;
}

void Grid::setup() {
	floor.load("images/grass.png");
	bump1.load("images/bump1.png");
	bump2.load("images/bump2.png");

}

void Grid::draw(float w, float h) {
	switch (piece) {
	case 0:
		floor.draw(position, w, h);
		break;
	case 1: 
		bump1.draw(position, w, h);
		break;
	case 2:
		bump2.draw(position, w, h);
		break;
		
	}
}
