//#include "ofxControlFloatClass.h"
//using namespace std;
//vector <ofxControlFloat*> CFvector;

#ifndef OFXCONTROLFLOAT
    #define OFXCONTROLFLOAT

#include "ofMain.h"
#include <iostream>
#include <vector>


using namespace std;

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
#endif


