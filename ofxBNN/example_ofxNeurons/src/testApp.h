#pragma once

#include "ofMain.h"
#include "Neurons_network.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		Neurons_network nn;
		vector<ofVec2f> event_vector;

		float event_vis_height, event_vis_width, event_vel, event_pos ;

};
