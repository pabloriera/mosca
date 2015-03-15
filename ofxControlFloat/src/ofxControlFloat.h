#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofxControlFloat
{
    public:

        ofxControlFloat();

        void set(const float);
        void update(ofEventArgs & args);

        operator float();

        ofxControlFloat& operator= (const ofxControlFloat&);
        ofxControlFloat& operator= (const float&);
        ofxControlFloat& operator= (const int&);

        float target;
        float value;
        float alpha;
};

//class ofxControlFloatSlider:
//{
//    public:
//
//        ofxControlFloatSlider();
//
//        void update(ofEventArgs & args);
//
//        ofxFloatSlider slider;
//        ofxControlFloat value;
//
//};

