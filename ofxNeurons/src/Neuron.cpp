#include "Neuron.h"

Neuron::Neuron(){

}

void Neuron::setup(size_t _id){

    id = _id;
    sp_bufferSize = 1024;
    sp_buff.assign(sp_bufferSize,0.0);
    sp_buff_ptr = 0;

    event = false;

    dt = 0.01;
//    I.alpha = dt;

    dc = 0;
    syn_type = 1;

    fr.Fs = 1/dt;
    FRset(.1,1);

    reset();
}

void Neuron::reset()
{

    //Iz parameters
    t=0;
    maxV = 30;
    minV = -80;


    a = 0.02;
    b = 0.2;
    c = -65;
    d = 8;
    V = -65;
    u = b*V;

    //Synaptic variables
    sp = 0;
    s0 = 0;
    tau = 1;

    // The neuron only behaves as excitatory or inhibotry if true. If false, it can behave both ways
    fix_syn_type = true;

    fr.v.assign(4, 0.0);

    sp_buff.assign(sp_bufferSize,0);

}


bool Neuron::update(){

    I = dc + Ibuf;

    float maxIdt = 50;

    if (I*dt > maxIdt)
        I = maxIdt/dt;

    V = V + (0.04*V*V + 5*V + 140 - u + I)*dt;
    u = u + a*(b*V-u)*dt;

    event = false;

    if (V > maxV)
    {
        event = true;
        V = c;
        u = u + d;
        s0 = syn_type;
    }

    //FRcalc();
    //FRscope.update(ofMap(FR,0,5,0,1));

    sp = sp - sp*dt/tau;
    sp = sp + s0;

    //if (sp<0.00001)
     //   sp = 0.0;

    sp_buff_ptr++;

    if(sp_buff_ptr>sp_bufferSize)
        sp_buff_ptr = 0;

    sp_buff[sp_buff_ptr] = sp;

//        for(int i = 0; i<sp_bufferSize-1;i++)
//            sp_buff[i]=sp_buff[i+1];
//        sp_buff[sp_bufferSize-1] = sp;

    //cout << "UPDATE_size=" << sp_buff.size() << endl;

    s0 = 0;
    Ibuf = 0;

    return event;
}

void Neuron::currentBuffer(float w, float d, Neuron* _neurona){

    int now = _neurona->sp_buff_ptr;
    int past = now - d;
    if (past<0)
        past += _neurona->sp_bufferSize;

    Ibuf += w * _neurona->sp_buff[ past ];

}



void Neuron::FRset(float Fc,float Q){

    //Set low pass filter parameters
    fr.Fc = Fc;
    fr.W = tan(PI*Fc/fr.Fs);
    fr.N = 1/(pow(fr.W,2) + fr.W/Q + 1);
    fr.B_0 = fr.N*pow(fr.W,2);
    fr.B1 = 2*fr.B_0;
    fr.B2 = fr.B_0;
    fr.A1 = 2*fr.N*(pow(fr.W,2) - 1);
    fr.A2 = fr.N*(pow(fr.W,2) - fr.W/Q + 1);

//  cout << fr.W << ",  " << fr.N << ",  " << fr.B_0 << ",  " << fr.B1 << ",  " << fr.B2 << ",  " << fr.A1 << ",  " << fr.A2 << ",  " << Fc << "\n";
}

void Neuron::FRcalc(){

    //Calculate FR

    float out;
    float in;
    in = (float) event;

    //Low pass filter 2nd order
    out = 100*in*fr.B_0 + fr.v[0]*fr.B1 + fr.v[1]*fr.B2 - fr.v[2]*fr.A1 - fr.v[3]*fr.A2;
    fr.v[3] = fr.v[2];
    fr.v[2] = out;
    fr.v[1] = fr.v[0];
    fr.v[0] = in;

    FR = out;
//        if (fr.v[3] < fr.v[2]) FRset(fr.Fc*=1.1,0.5);
//        else FRset(fr.Fc*=0.9,0.5);

    //cout << in <<  ",  "<< out << "\n";

}
//
//void Neuron::drawCircle(){
//
//    ofFill();
//    ofSetColor(color, 255*ofNormalize(V,-100,30) );
//    vis_circle_radio = 0.95f * vis_circle_radio + ofMap(V,-65,30,0,visEvent_height/2.0f) * 0.05f;
//    //cout << tamanio << "\n";
//    ofCircle(visCircle_pos.x, visCircle_pos.y, vis_circle_radio+vis_circle_radio0);
//    //ofCircle(vis_pos.x, vis_pos.y, 10);
//}
