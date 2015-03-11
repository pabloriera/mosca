#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

nn.setup();
nn.add_neuron(10);


}

//--------------------------------------------------------------
void testApp::update(){

nn.update();


}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0,0,0);
    nn.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

//nn.neurons[0]->dc = ofMap(x,0,ofGetWidth(),0,100);
nn.set_currents(ofMap(x,0,ofGetWidth(),0,100), ofMap(y,0,ofGetHeight(),0,50));

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}
