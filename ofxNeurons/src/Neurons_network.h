#pragma once

#define MAXN 100
#include <vector>
#include "Neuron.h"
#include "Synapse.h"

float drand();
float random_normal();

class Neurons_network {
public:
    Neurons_network();

    void setup();
    void update();

    void add_neuron(int num=1);
    void remove_neuron(size_t id);
    void add_synapse(size_t source_id,size_t target_id );
    void remove_synapse(size_t id);

    void add_all_synapses();

    void reset();
    void draw();

    void set_dts(float dt);
    void set_currents(float dc_mean, float dc_std);

    void set_syn_w_matrix(float type_prop,float syn_w_mean, float syn_w_weight);
    void set_syn_d_matrix(float syn_d_mean, float syn_d_weight);

    void togg_syn_matrix();


    Neuron* neuronId(size_t id);
    Synapse* synapseId(size_t id);

    vector <Neuron*> neurons;
    vector<Synapse*> synapses;

    size_t neuron_id,synapse_id;

    bool bool_syn_matrix;


};
