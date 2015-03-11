#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    p.x = ofGetWidth()/2;
    p.y = ofGetHeight()/2;
    pb.setup("127.0.0.1",12346,12345);

    pb.OSCreceive_map("/pos/x",&(p.x),0,100,0,ofGetWidth());
    pb.OSCreceive_map("/pos/y",&(p.y),0,100,0,ofGetHeight());
    pb.OSCsend_map("/mousepos/x",&mX);

    pb.OSCreceive_event("/event",&eventReceived);
    ofAddListener(eventReceived, this, &ofApp::cambiarColor);



}

void ofApp::cambiarColor(int & arg){

    bg.set(ofRandom(255),ofRandom(255),ofRandom(255));

}


//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0,0,0);
    ofSetColor(bg);
    ofCircle(p.x,p.y,50);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key=='r'){
        ofNotifyEvent(eventReceived, key, this);
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

    mX = x;

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

    pb.send("/button",button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
