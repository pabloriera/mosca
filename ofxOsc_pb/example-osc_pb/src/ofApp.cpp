#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    p.x = 100;
    p.y = 200;
    pb.setup("127.0.0.1",12346,12345);

    pb.OSCreceive_map("/pos/x",&(p.x),0,100,0,ofGetWidth());
    pb.OSCreceive_map("/pos/y",&(p.y),0,100,0,ofGetHeight());
    pb.OSCsend_map("/mousepos/x",&mX);

    ofAddListener(keyPressedEvent, //the ofEvent that we want to listen to. In this case exclusively to the circleEvent of redCircle (red circle) object.
                  this, //pointer to the class that is going to be listening. it can be a pointer to any object. There's no need to declare the listeners within the class that's going to listen.
                  &ofApp::cambiarColorFondo);//pointer to the method that's going to be called when a new event is broadcasted (callback method). The parameters of the event are passed to this method.

}

void ofApp::cambiarColorFondo(int & arg){

    bg.set(ofRandom(255),ofRandom(255),ofRandom(255));

}


//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(bg);
    ofCircle(p.x,p.y,10);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key=='r'){
        ofNotifyEvent(keyPressedEvent, key, this);
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
