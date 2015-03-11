#include "ofxOsc_pb.h"

void ofxOsc_pb::OSCreceive_map(string label, float* x, float minX, float maxX, float minY, float maxY)
{
    receive_t rec(x, minX, maxX, minY, maxY);

    d_receives.insert( make_pair(label, rec));
}

void ofxOsc_pb::OSCreceive_event(string label,ofEvent<int> *event)
{
    receive_t rec(event);
    d_receives.insert( make_pair(label, rec));
}

void ofxOsc_pb::OSCsend_map(string label, float* x)
{
    send_map_t p(x);

    d_sends_map.insert( make_pair(label, p));
}

void ofxOsc_pb::OSCsend_map(string label, int* x)
{
    send_map_t p(x);

    d_sends_map.insert( make_pair(label, p));
}

//void ofxOsc_pb::OSCsend_event(string label,ofEvent<int> *event)
//{
//    ofAddListener(*event, this, &ofxOsc_pb::send_events);
//
//}
//void ofxOsc_pb::send_events(ofEventArgs & args)
//{
//
//
//
//}


void ofxOsc_pb::setup(string ip, int send_port,int receive_port){

    oscreceiver.setup(receive_port);
    oscsender.setup(ip,send_port);

    ofAddListener(ofEvents().update, this, &ofxOsc_pb::update);

}

void ofxOsc_pb::update(ofEventArgs & args){

    //SENDER
    for(auto& element : d_sends_map){
            if (element.second.typex=="float")
            {
                if(*(element.second.fx)!=element.second.fx_old)
                {
                    element.second.fx_old = *(element.second.fx);
                    ofxOscMessage m;
                    m.setAddress(element.first);
                    m.addFloatArg(*(element.second.fx));
                    oscsender.sendMessage(m);
                }

            }

            else if (element.second.typex=="int")
            {
                if(*(element.second.ix)!=element.second.ix_old)
                {
                    element.second.ix_old = *(element.second.ix);
                    ofxOscMessage m;
                    m.setAddress(element.first);
                    m.addIntArg(*(element.second.ix));
                    oscsender.sendMessage(m);
                }
            }


    }

    //RECEIVER
	while (oscreceiver.hasWaitingMessages()) {
		ofxOscMessage m;
		oscreceiver.getNextMessage(&m);


		//Find key from receives dictionary that matches osc address.
        dict_receive_t::iterator d_pair = d_receives.find( m.getAddress() );
        if (d_pair != d_receives.end())
        {
            //One arg methods
            if(m.getNumArgs()==1)
            {
                if(m.getArgType(0) == OFXOSC_TYPE_INT32)
                {
                    float x = (float) m.getArgAsInt32(0);
                    d_pair->second.action(x);
                }
                else if(m.getArgType(0) == OFXOSC_TYPE_FLOAT)
                {
                    float x = (float) m.getArgAsFloat(0);
                    d_pair->second.action(x);
                }
            }
            //Zero arg methods
            else if(m.getNumArgs()==0)
            {
                d_pair->second.action();
            }
        }

	}
}

void ofxOsc_pb::send(string label, string s){
    ofxOscMessage m;
    m.setAddress(label);
    m.addStringArg(s);
    oscsender.sendMessage(m);
}

void ofxOsc_pb::send(string label, int i){
    ofxOscMessage m;
    m.setAddress(label);
    m.addIntArg(i);
    oscsender.sendMessage(m);
}

void ofxOsc_pb::send(string label, float f){
    ofxOscMessage m;
    m.setAddress(label);
    m.addFloatArg(f);
    oscsender.sendMessage(m);
}
