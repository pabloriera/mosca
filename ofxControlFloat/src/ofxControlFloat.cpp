#include "ofxControlFloat.h"
#define eps_float 0.00001

ofxControlFloat::ofxControlFloat()
{
    value = 0;
    target = 0;
    alpha = 0.05;
    ofAddListener(ofEvents().update,this, &ofxControlFloat::update);

//    CFvector.push_back(this);
}

void ofxControlFloat::update(ofEventArgs & args)
{
    //lowpass tau=1/6.28/freq
    //value = value + (target - value)*dt/tau
    //value = value*(1-alpha) + target*alpha;

    float increment = (target - value)*alpha;
    if MAX(increment, eps_float);
        value += increment;


}

void ofxControlFloat::set(const float param)
{
    value = param;
}

ofxControlFloat::operator float()
{
    return value;
}

ofxControlFloat& ofxControlFloat::operator= (const ofxControlFloat& CF)
{
    target = CF.target;
    return *this;
}

ofxControlFloat& ofxControlFloat::operator= (const float& param)
{
    target = param;
    return *this;
}

ofxControlFloat& ofxControlFloat::operator= (const int& param)
{
    target = param;
    return *this;
}
