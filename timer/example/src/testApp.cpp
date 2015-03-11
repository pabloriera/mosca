
#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){


    gui.setup(); // most of the time you don't need a name
	gui.add(interval.setup( "interval (us)", 1, 1, 1000000 ));
    gui.add(freq.setup( "frecuencia", 1, 0.01, 80 ));

    ofSetFrameRate(200);

    timer = new chronoTimer<testApp>(*this,&testApp::doit);
    timer->startThread(true, false);

    interval.addListener(this,&testApp::setInterval);
    freq.addListener(this,&testApp::setFreq);

    c=0;

}

void testApp::setFreq(float &freq)
{
    int aux = (int)1e6/freq;
    timer->setInterval(aux);
}

void testApp::setInterval(int &interval)
{
    timer->setInterval(interval);
}

void testApp::doit(){

    c++;
    bang = true;

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

        if(bang)
        {
            ofSetColor(255,255,255);
            ofCircle(ofGetWidth()/2,ofGetHeight()/2,50);
            bang = false;
        }


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
