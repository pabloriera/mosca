#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    p.x = 100;
    p.y = 200;
    pb.setup("127.0.0.1",12346,12345);

    pb.OSCreceive_map("/pos/x",&(p.x),0,100,0,ofGetWidth());
    pb.OSCreceive_map("/pos/y",&(p.y),0,100,0,ofGetHeight());
    pb.OSCsend_map("/mousepos/x",&mX);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofCircle(p.x,p.y,10);


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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

//    ofEventArgs args;
//    ofNotifyEvent(pb.newEvent,args,this);
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
