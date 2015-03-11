#pragma once

#define RATE 4.0

#include "ofMain.h"

#include "ofxGui.h"

#include "ofxTimerThread.h"


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
        void setFreq(float &freq);
		void doit();

        bool bang;

        ofxTimerThread<testApp> *timer;

        ofxIntSlider interval;
        ofxFloatSlider freq;

        ofxPanel gui;
        int c;

};

