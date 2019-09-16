#include "Endpoint.h"

bool Endpoint::collision(Ball b) {
	return false;
}

void Endpoint::setAdj(int x) {
	adjTile = x;
}

void Endpoint::setup() {
	end.load("images/end.png");
}

int Endpoint::getAdj() {
	return adjTile;
}

void Endpoint::draw(float w, float h) {
	
    end.draw(position, w, h);

}

void Endpoint::setPosition(ofVec2f pos, float dim){
    switch (orientation) {
        case 0: //bottom
            position = ofVec2f(pos.x, pos.y + dim);
            break;
        case 1: //left
            position = ofVec2f(pos.x - dim, pos.y);
            break;
        case 2: //top
            position = ofVec2f(pos.x, pos.y - dim);
            break;
        case 3: //right
            position = ofVec2f(pos.x + dim, pos.y);
            break;
    }
}

ofVec2f Endpoint::getPosition(){
    return position;
}

void Endpoint::setOrientation(int x) {
	orientation = x; //0 = bottom, 1 = Left, 2 = top, 3 = right
}
