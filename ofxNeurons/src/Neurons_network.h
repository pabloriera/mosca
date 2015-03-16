#pragma once

#define MAXN 100
#include "graph.h"
#include "Neuron.h"
#include "Synapse.h"

float drand();
float random_normal();

class Neurons_network {
public:
    Neurons_network();

    void setup(Graph& G);
    void update();

    void reset();

    void set_dts(float dt);
    void set_currents(float dc_mean, float dc_std);

    void set_syn_w_matrix(float type_prop,float syn_w_mean, float syn_w_weight);
    void set_syn_d_matrix(float syn_d_mean, float syn_d_weight);

    void togg_syn_matrix();

    bool bool_syn_matrix;

    Graph* G;

    NodeMap<Neuron> neurons;
    LinkMap<Synapse> synapses;

};
