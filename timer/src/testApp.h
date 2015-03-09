#pragma once

#define HOST "localhost"
#define PORT 12345

#define RATE 4.0

#include "ofMain.h"

#include "ofxOsc.h"
#include "ofxGui.h"

#include "chronoTimer.h"


class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void exit();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

        void setInterval(int & interval  );
		void doit();


        chronoTimer<testApp> *timer;

        ofxOscSender sender;

        ofxIntSlider interval;

        ofxPanel gui;
        int c;

};

