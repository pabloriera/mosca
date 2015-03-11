#pragma once

#include <map>
#include <string>
#include "stdlib.h"
#include "ofxOsc.h"

using namespace std;


class ofxOsc_pb
{
    private:

    class receive_t
    {
        public:
        receive_t(float* _y, float _minX, float _maxX, float _minY, float _maxY) { y = _y;  minX = _minX;  maxX = _maxX; minY = _minY;  maxY = _maxY; type="map"; }
        receive_t(ofEvent<int> *event_) { event = event_; type = "event"; }

        float* y;
        float minX, maxX, minY, maxY;
        ofEvent<int> *event;
        string type;

        void action()
        {
            if(type == "event")
            {
                int aux=0;
                ofNotifyEvent(*event,aux);
            }

        }
        void action(float x)
        {
            if(type == "map")
                *y = ofMap(x, minX, maxX,minY, maxY);
        }


    };

    //template<typename U>
    class send_map_t
    {
        public:
            send_map_t(float* _fx)
            {
                typex = "float";
                fx = _fx;
                fx_old = *_fx;
            }


            send_map_t(int* _ix)
            {
                typex = "int";
                ix = _ix;
                ix_old = *_ix;
            }

            string typex;

            float* fx;
            float fx_old;
            int* ix;
            int ix_old;

    };

    typedef map<string, receive_t> dict_receive_t;
    typedef map<string, send_map_t> dict_send_map_t;

    //template<typename U> struct A {};
    //typedef map<string, send_data<U,A<U>> map_send;

    dict_receive_t d_receives;
    dict_send_map_t d_sends_map;


    ofxOscReceiver oscreceiver;
    ofxOscSender oscsender;

    void call_ofMap(const string& keyString, float valor);

    public:

        ofxOsc_pb(){};

        void OSCreceive_map(string label, float* x, float minX, float maxX, float minY, float maxY);
        void OSCsend_map(string label, float* x);
        void OSCsend_map(string label, int* x);

        void OSCreceive_event(string label,ofEvent<int> *event);

        void setup(string ip, int send_port,int receive_port);

        void update(ofEventArgs & args);
        void test(const void * sender,ofEventArgs & args);

        ofEvent<ofEventArgs> newEvent;

        void send(string label,string s);
        void send(string label,float f);
        void send(string label,int i);
};
