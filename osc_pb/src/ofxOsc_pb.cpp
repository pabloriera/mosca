#include "ofxOsc_pb.h"

void OSC_pb::OSCmap_receive(string label, float* x, float minX, float maxX, float minY, float maxY)
{
    paquete p(x, minX, maxX, minY, maxY);

    m.insert( make_pair(label, p));

}

void OSC_pb::call_ofMap(const string& keyString, float valor)
{
	map_receive::const_iterator aux = m.find(keyString);
	if (aux != m.end())
	{

        paquete p = aux->second;

        *(p.x) = ofMap(valor,p.minX,p.maxX,p.minY,p.maxY);
    }
}


void OSC_pb::setup(string ip, int send_port,int receive_port){

    oscreceiver.setup(receive_port);
    oscsender.setup(ip,send_port);


    ofAddListener(ofEvents().update, this, &OSC_pb::update);
    //ACOMODAR!!
}

void OSC_pb::update(ofEventArgs & args){

//recibe de pd
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
