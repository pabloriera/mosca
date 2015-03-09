
#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){




    gui.setup(); // most of the time you don't need a name
	gui.add(interval.setup( "interval", 1, 1, 1000000 ));

    ofSetFrameRate(10);
    sender.setup(HOST, PORT);


    timer = new chronoTimer<testApp>(*this,&testApp::doit);
    timer->startThread(true, false);

    interval.addListener(this,&testApp::setInterval);

    c=0;

}

void testApp::setInterval(int &interval)
{
    timer->setInterval(interval);
}

void testApp::doit(){

    c++;
    cout << c << endl;

}

void testApp::exit(){
	timer->stopThread();
}

//--------------------------------------------------------------
void testApp::update(){


}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0,0,0);

    gui.draw();

    string str = "";
    str += ofToString(c);

    ofDrawBitmapString(str, 50, 100);


}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

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
