#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

nn.setup();
nn.add_neuron(10);
nn.add_all_synapses();

event_vis_width = 5;
event_pos = 0;
event_vel = 1;
}

//--------------------------------------------------------------
void testApp::update(){

nn.update();

//for(size_t i = 0; i < nn.neurons.size(); i++)
//    cout << setprecision(0) <<  nn.neurons[i]->V << "  ";
//
//cout << endl;
//
//for(size_t i = 0; i < nn.neurons.size(); i++)
//    cout << setprecision(0) << nn.neurons[i]->I << "  ";
//
//cout << endl;
}

//--------------------------------------------------------------
void testApp::draw(){

    ofBackground(0,0,0);

    event_vis_height = ofGetHeight()*0.75/nn.neuron_id;

    event_pos += event_vel;

    for(size_t i = 0; i < nn.neurons.size(); i++)
    {

        if(event_pos>ofGetWidth()*0.9){
            event_pos = ofGetWidth()*0.1;
            event_vector.clear();
        }

        if(nn.neurons[i]->event){
            event_vector.push_back ( ofVec2f(event_pos,i*event_vis_height*1.2 + ofGetHeight()*0.05 ) );
        }

    }


    ofFill();
    ofSetColor(255,255,255);

    for(size_t i=0; i< event_vector.size(); i++){
        ofRect(event_vector[i].x, event_vector[i].y, event_vis_width , event_vis_height);
    }

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

    if(key==OF_KEY_BACKSPACE)
        nn.set_syn_w_matrix(0.5,ofRandom(50),ofRandom(20));

    if(key=='r')
        nn.reset();
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

//nn.neurons[0]->dc = ofMap(x,0,ofGetWidth(),0,100);
nn.set_currents(ofMap(x,0,ofGetWidth(),0,300), ofMap(y,0,ofGetHeight(),0,80));

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}
