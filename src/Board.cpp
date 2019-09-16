#include "Board.h"

//have piece have different states, 0-4;
//0 = floor, 1 = /, 2 = \; maybe inside the interaction class
//0. add a floor object to interaction class
//1. Build board in memory, adding floor object from the interaction class by the size of the sprite
//2. Select a random edge tile using the algorithm in phone
//3. Get tile position - determine which edge, offset the selected tile position by one tile size and place end point
//4. determine how many bumpers to put up
//5. from selected tile, randomize first bumper location - see phone
//6. move onto ball

//build board vertically
//Keep the loops for drawing function
//The board in this state can be built without drawing

void Board::setup() {
	endPoint.setup();
}

void Board::buildBoard() {//position x and y will change, size will not
    /*
    If it is called as a level change, clear all the vectors
    If the board is already empty, assuming new game, skip clearing
    */
	if (!(board.empty())){ //when called after level change
		board.clear();
        offBoard.clear();
        start.clear();
	}
    
	ofSeedRandom(ofGetSystemTimeMicros()); //Get new random seed
    
    /*
    Set up dummy board pieces and assigns all grid objects a coordinate (x,y)
    */
    
	for (int y = 0; y < size; y++) {
		for (int x = 0; x < size; x++) {
			temp.setup();
			temp.setY(y);
			temp.setX(x);
			temp.setPiece(0);
			board.push_back(temp);
		}
	}//fills board of the level size with tile indicators on

	
	random = (int)ofRandom(3); //Selects which side of the board to randomly select an endpoint on. 0 = bottom, 1 = Left, 2 = top, 3 = right
    
	endPoint.setAdj(selectEnd(random)); //endpoint.adjTile holds the tile to go off of
	endPoint.setOrientation(random); //endPoint knows what side it's on
    
    int test = endPoint.getAdj();
    
	buildBumpers(endPoint.getAdj()); //Builds random bumpers on that board
    setGridPos();
    
    endPoint.setPosition(board[test].getPosition(), width);
    
	if (bumpSize > 0) {
		randomBump();
    }//Sets up randomBumpers if buildBumpers did not use up the max # of bumpers for the level
    
    
    for(int y = 0, flag = 1, top = 0, right = 0, bottom = 0, left = 0; y < (size * 4); y++){
        //flag: 1 = top; 2 = right; 3 = bottom; 4 = left
        startPoint.setup();
        
        switch(flag){
            case 1:
                //call setPositionTop
                startPoint.setPositionTop(board[0].getPosition(), top, width, size);
                
                if(top == (size - 1)){
                    flag++;
                }
                top++;
                break;
            
            case 2:
                //call setPositionRight
                startPoint.setPositionRight(board[0].getPosition(), right, width, size);
                
                if(right == (size - 1)){
                    flag++;
                }
                right++;
                break;
                
            case 3:
                //call setPositionBottom
                startPoint.setPositionBottom(board[0].getPosition(), bottom, width, size);
                
                if(bottom == (size - 1)){
                    flag++;
                }
                bottom++;
                break;
                
            case 4:
                //call setPositionLeft
                startPoint.setPositionLeft(board[0].getPosition(), left, width, size);
                
                if(left == (size - 1)){
                    flag++;
                }
                left++;
                break;
        }//end of switch
        
        if(startPoint.getPosition() != endPoint.getPosition()){
            start.push_back(startPoint);
        }
        
    }//sets up an array of startPoints called start
    
    //Problem 1: Endpoint and startpoint are on top of each other
    //Problem 2: Missing start points for end condition of each side


}


void Board::setGridPos() { 

	int startX = (ofGetWindowWidth() / 2) - ((width * size) / 2); //starting point to center the board
	int startY = (ofGetWindowHeight() / 2) - ((height * size) / 2);
	for (int x = 0; x < size; x++) {
		for (int y = 0; y < size; y++) {
			int posX = startX + (width * x);
			int posY = startY + (height * y);
			//board[findIndex(x, y)].draw(posX, posY, width, height, board[findIndex(x, y)].getPiece());
			board[findIndex(x, y)].setPosition(posX, posY);
			//After this, can access every squares position. This will be useful for setting end point and the edge squares
		}
		
	}
	//endPoint.draw(board[endPoint.getAdj()].getPosition(), width, height);
    //array of startPoint is in start, get board[0].getPosition() to get position of 0, 0
    //Top: 0 to size-1, Right: size to (size + size-1), Bottom: 

}

void Board::draw(){
    
    for (int i = 0; i < board.size(); i++){
        board[i].draw(width, height);
    }
    
    for (int x = 0; x < start.size(); x++){
        start[x].draw(width, height);
    }
    
    endPoint.draw(width, height);
}

void Board::drawBlank(){
    vector<Grid> blankBoard;
    int startX = (ofGetWindowWidth() / 2) - ((width * size) / 2); //starting point to center the board
    int startY = (ofGetWindowHeight() / 2) - ((height * size) / 2);
    
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            temp.setup();
            temp.setY(y);
            temp.setX(x);
            temp.setPiece(0);
            blankBoard.push_back(temp);
        }
    }
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            int posX = startX + (width * x);
            int posY = startY + (height * y);
            //board[findIndex(x, y)].draw(posX, posY, width, height, board[findIndex(x, y)].getPiece());
            blankBoard[findIndex(x, y)].setPosition(posX, posY);
            //After this, can access every squares position. This will be useful for setting end point and the edge squares
        }
        
    }
    for (int i = 0; i < board.size(); i++){
        blankBoard[i].draw(width, height);
    }
}


int Board::selectEnd(int random) {
	switch (random) {
	case 0: //bottom
		//int adj = 
		return ((int)ofRandom((size * size - size), (size*size - 1)));
		//break;
	case 1: //Left side
		return (0 + (int)ofRandom(0, size - 1) * size);
		//break;
	case 2: //top
		return ((int)ofRandom(0, size - 1));
		//break;
	case 3: //right side
		return(size * (int)ofRandom(1, size)) - 1;
		//break;
	}
}

void Board::setSize(int x) {
	size = x;
}

void Board::buildBumpers(int index) {
	//ofSeedRandom(ofGetSystemTimeMicros());
	//Information I need:
	// 1. Tile that endpoint is next to (endPoint.getAdj())
	// 2. Which side the end point is on (random) if 0 = bottom, 1 = left side, 2 = top side, 3 = bottom
	// 3. bumpSize, how many bumpers to make
	// 4. A method to randomly select which bumper orientation
	int curX = board[index].getX(); //what to search for
	int curY = board[index].getY();
	int newX;
	int newY;
	int newIndex;
	int piece;
	int seed = (int)ofRandom(10000);

	if (seed & 1) {
		piece = 1;
	}
	else {
		piece = 2;
	} //checks if random seed is odd or even
	//assigns bumper to place

	if (bumpSize == 0) {
		return;
	}

		switch (random) { //index coming in is the tile being worked on, random determines which way the ball travels
		case 0: //going up, only need to find a random y
			newY = (int)ofRandom(0, curY - 1);
			newIndex = findIndex(curX, newY);
			break;
		case 1:
			newX = (int)ofRandom(curX + 1, size - 1);
			newIndex = findIndex(newX, curY);
			break;
		case 2:
			newY = (int)ofRandom(curY + 1, size - 1);
			newIndex = findIndex(curX, newY);
			break;
		case 3:
			newX = (int)ofRandom(0, curX - 1);
			newIndex = findIndex(newX, curY);
			break;
		}

		//checkOffBoard(int newIndex); This is for checking if the newIndex is on the blocked list
		if (checkOffBoard(newIndex)) {
			newIndex = fixBlock(curX, curY);
			if (newIndex == -1) {
				//change current location bumper, update random, call buildboard again, return after to return this call when it comes back
				if (board[index].getPiece() == 1) {
					board[index].setPiece(2);
				}
				else {
					board[index].setPiece(1);
				}
				setNewOrient(board[index].getPiece());
				buildBumpers(index);
				return;
			}
			else {
				board[newIndex].setPiece(piece);
				bumpSize--;
				setNewOrient(piece);
				offBoard.push_back(newIndex);
				buildBumpers(newIndex);
				return;
			}
		}
		else {
			board[newIndex].setPiece(piece);
			bumpSize--;
			setNewOrient(piece);
			offBoard.push_back(newIndex);
			buildBumpers(newIndex);
			return;
		}
		
	
}

int Board::findIndex(int x, int y) {

	for (int i = 0; i < size; i++) { //Checking top row of grid (first row of tiles)
		if (board[i].getX() == x) { //Check X
			for (int t = 0; t < size; t++) { //Check Y
				int mult = t * size; //If y = 0, mult = 0, if y = max, mult = size * size - 1
				if (board[i + mult].getY() == y) { //i + mult would give us going down Y
					return i + mult; //return the index found
				}
			}
		}
	}
}

bool Board::checkOffBoard(int x) {//Returns true if index thrown in is on the blocked list
	if (offBoard.size() == 0) {
		return false;
	}
	for (int i = 0; i < offBoard.size(); i++) {
		if (x == offBoard[i]) {
			return true;
		}
	}

	return false;
}

int Board::fixBlock(int x, int y) { //if successful, return correct index, if not, return -1
	int test;
	int testX = x, testY = y;
	switch (random) { //index coming in is the tile being worked on, random determines which way the ball travels
	case 0:
		for (int i = 0; i <= y - 1; i++) {
			testY -= 1;
			test = findIndex(x, testY);
			if (!checkOffBoard(test)) {
				return test;
			}
		}
		return -1; //Fail Case
		break;
	case 1:
		for (int i = x; i <= size - 1; i++) {
			testX += 1;
			test = findIndex(testX, y);
			if (!checkOffBoard(test)) {
				return test;
			}
		}
		return -1;
		break;
	case 2:
		for (int i = y; i <= size - 1; i++) {
			testY += 1;
			test = findIndex(x, testY);
			if (!checkOffBoard(test)) {
				return test;
			}
		}
		return -1;
		break;
	case 3:
		for (int i = 0; i <= x - 1; i++) {
			testX -= 1;
			test = findIndex(testX, y);
			if (!checkOffBoard(test)) {
				return test;
			}
		}
		return -1;
		break;
	}
}

void Board::setNewOrient(int piece) { //piece = 1 "/", piece = 2 "\"
	switch (random) {//current orientation
	case 0: //going up
		if (piece == 1) {
			random = 1;
		}
		else if (piece == 2) {
			random = 3;
		}
		break;
	case 1: //going right
		if (piece == 1) {
			random = 0;
		}
		else if (piece == 2) {
			random = 2;
		}
		break;
	case 2: //going down
		if (piece == 1) {
			random = 3;
		}
		else if (piece == 2) {
			random = 1;
		}
		break;
	case 3: //going left
		if (piece == 1) {
			random = 2;
		}
		else if (piece == 2) {
			random = 0;
		}
		break;
	}
	return;
}

void Board::blockList() {

}

void Board::randomBump() {
	ofSeedRandom(ofGetSystemTimeMicros());
	while (bumpSize > 0) {
		int x = (int)ofRandom((size * size) - 1);
		if (board[x].getPiece() == 0 && (!(checkOffBoard(x)))) {
			int y = (int)ofRandom(1, 2);
			board[x].setPiece(y);
			bumpSize--;
		}
	}
}
