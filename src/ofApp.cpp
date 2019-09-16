#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	board.setup();
	board.buildBoard();
    startTime = ofGetElapsedTimeMillis();
    triggerTime = false;
    state = 1;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    //depending on game_state
    /*
     Build board
     erase bumpers from view: Draw grass on top but not make it interactable. Loop through board and if board piece is not blank, draw on top
     change game_state to allow player to click on start point
     change game_state to not allow player to click on board
     check win condition
     
    */
    float timer = ofGetElapsedTimeMillis() - startTime;
    if (timer > 5000 && state == 1){
        triggerTime = true;
    }

    
}

//--------------------------------------------------------------
void ofApp::draw(){
	board.draw();
    if(triggerTime){
        board.drawBlank();
        triggerTime = false;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    //get position of mouse when released, check collision with startPoint if game_state = 1
    //if startPoint and mouse collide, change game_state, create player, move player
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
