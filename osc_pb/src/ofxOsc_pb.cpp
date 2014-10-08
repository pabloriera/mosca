#include "ofxOsc_pb.h"

void OSC_pb::OSCmap_receive(string label, float* x, float minX, float maxX, float minY, float maxY)
{
    receive_data p(x, minX, maxX, minY, maxY);

    receives_list.insert( make_pair(label, p));
}

void OSC_pb::OSCmap_send(string label, float* x)
{
    send_data p(x);

    sends_list.insert( make_pair(label, p));
}

void OSC_pb::OSCmap_send(string label, int* x)
{
    send_data p(x);

    sends_list.insert( make_pair(label, p));
}

void OSC_pb::call_ofMap(const string& keyString, float valor)
{
	map_receive::const_iterator aux = receives_list.find(keyString);
	if (aux != receives_list.end())
	{
        receive_data p = aux->second;

        *(p.x) = ofMap(valor,p.minX,p.maxX,p.minY,p.maxY);
    }
}

void OSC_pb::setup(string ip, int send_port,int receive_port){

    oscreceiver.setup(receive_port);
    oscsender.setup(ip,send_port);

    ofAddListener(ofEvents().update, this, &OSC_pb::update);

    ///Prueba eventos y mensajes
    ofAddListener(newEvent, this, &OSC_pb::test );

}

///Prueba eventos y mensajes
void OSC_pb::test(const void * sender,ofEventArgs & args){

    cout << sender << endl;
    cout << "hola" << endl;
}
///

void OSC_pb::update(ofEventArgs & args){

    //manda
    for(const auto& element : sends_list){
        cout << *(element.second.fx) << endl;
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

void OSC_pb::send(string label,string s){
    ofxOscMessage m;
    m.setAddress(label);
    m.addStringArg(s);
    oscsender.sendMessage(m);
}

void OSC_pb::send(string label,int i){
    ofxOscMessage m;
    m.setAddress(label);
    m.addIntArg(i);
    oscsender.sendMessage(m);
}

void OSC_pb::send(string label, float f){
    ofxOscMessage m;
    m.setAddress(label);
    m.addFloatArg(f);
    oscsender.sendMessage(m);
}
