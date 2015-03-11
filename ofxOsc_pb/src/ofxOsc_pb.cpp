#include "ofxOsc_pb.h"

void ofxOsc_pb::OSCreceive_map(string label, float* x, float minX, float maxX, float minY, float maxY)
{
    receive_data p(x, minX, maxX, minY, maxY);

    receives_list.insert( make_pair(label, p));
}

void ofxOsc_pb::OSCsend_map(string label, float* x)
{
    send_data p(x);

    sends_list.insert( make_pair(label, p));
}

void ofxOsc_pb::OSCsend_map(string label, int* x)
{
    send_data p(x);

    sends_list.insert( make_pair(label, p));
}

void ofxOsc_pb::call_ofMap(const string& keyString, float valor)
{
	map_receive::const_iterator aux = receives_list.find(keyString);
	if (aux != receives_list.end())
	{
        receive_data p = aux->second;

        *(p.x) = ofMap(valor,p.minX,p.maxX,p.minY,p.maxY);
    }
}

void ofxOsc_pb::setup(string ip, int send_port,int receive_port){

    oscreceiver.setup(receive_port);
    oscsender.setup(ip,send_port);

    ofAddListener(ofEvents().update, this, &ofxOsc_pb::update);

    ///Prueba eventos y mensajes
    ofAddListener(newEvent, this, &ofxOsc_pb::test );

}

///Prueba eventos y mensajes
void ofxOsc_pb::test(const void * sender, ofEventArgs & args){

   // cout << sender << endl;
   // cout << "hola" << endl;
}
///

void ofxOsc_pb::update(ofEventArgs & args){

    //manda
    for(auto& element : sends_list){
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

    //recibe
	while (oscreceiver.hasWaitingMessages()) {
		ofxOscMessage m;
		oscreceiver.getNextMessage(&m);

		//Ejecuta los metodos segun el key.

		if(m.getArgType(0) == OFXOSC_TYPE_INT32)
                call_ofMap(m.getAddress(),m.getArgAsInt32(0) );
        if(m.getArgType(0) == OFXOSC_TYPE_FLOAT)
                call_ofMap(m.getAddress(),m.getArgAsFloat(0) );
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
