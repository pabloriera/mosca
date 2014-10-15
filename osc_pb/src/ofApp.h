#pragma once

#include "ofMain.h"
#include "ofxOsc_pb.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofVec2f p;
        OSC_pb pb;
        int mX;

        ofEvent<int> keyPressedEvent;

        void cambiarColorFondo(int & arg);

        ofColor bg;
};
