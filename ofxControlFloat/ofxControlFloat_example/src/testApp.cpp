#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){



    f.set(1);

    cout << f << endl;
    cout << f+1 << endl;
    cout << 1+f << endl;
    cout << f-1 << endl;
    cout << 1-f << endl;
    cout << f*2 << endl;
    cout << 2*f << endl;
    cout << f/2 << endl;
    cout << 2/f << endl;

}

//--------------------------------------------------------------
void testApp::update(){

 //   fx.update();
 //   fy.update();

}

//--------------------------------------------------------------
void testApp::draw(){

    ofCircle(fx,fy,50);

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
cout << fx << endl;
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

    fx = x;
    fy = y;

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

cout << "h" <<endl;

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}
