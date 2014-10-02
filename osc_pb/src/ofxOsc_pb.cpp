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


void OSC_pb::setup(string ip, int port ){

    oscsender.setup(ip,port);
    oscreceiver.setup(port);
    ofAddListener(ofEvents().update, this, &OSC_pb::update);

    //ACOMODAR!!
}

void OSC_pb::update(ofEventArgs & args){

//recibe de pd
	while (oscreceiver.hasWaitingMessages()) {
		ofxOscMessage n;
		oscreceiver.getNextMessage(&n);

		//Ejecuta los metodos segun el key.
		call_ofMap(n.getAddress(),n.getArgAsFloat(0) );

	}
}
