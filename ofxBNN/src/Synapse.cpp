#include "Synapse.h"

Synapse::Synapse(){
    weight = 0;
    delay = 0;
}

void Synapse::random_weight(float _min,float _max){

    weight = ofRandom(_min,_max);
}
void Synapse::set(float w,float d){

    weight = w;
    delay = d;
}
