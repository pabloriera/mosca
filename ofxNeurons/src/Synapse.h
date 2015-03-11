#pragma once

#include "ofMain.h"
#include "Neuron.h"

class Synapse {
public:
    Synapse();

    void set(float w, float d);
    void update();
    void random_weight(float min, float max);

    Neuron* from;
    Neuron* to;

    size_t id;

    ofxControlFloat weight, delay;
};
