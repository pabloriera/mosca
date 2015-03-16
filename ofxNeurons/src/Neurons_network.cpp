#include "Neurons_network.h"

Neurons_network::Neurons_network(){

}

void Neurons_network::setup(Graph& G_)
{

    G = &G_;
    bool_syn_matrix = true;

    for(vector<Node>::iterator it = G->nodes.begin(); it != G->nodes.end(); ++it)
    {
        neurons[*it].setup();
    }

}

void Neurons_network::update()
{
    for(vector<Node>::iterator it = G->nodes.begin(); it != G->nodes.end(); ++it)
    {
        neurons[*it].update();
    }

    if (bool_syn_matrix)
        for(vector<Link>::iterator it = G->links.begin(); it != G->links.end(); ++it)
        {
            synapses[*it].to->currentBuffer( synapses[*it].weight, synapses[*it].delay, &neurons[*( (*it).from) ] );
        }
}

void Neurons_network::set_currents(float dc_mean, float dc_std)
{
    for(vector<Node>::iterator it = G->nodes.begin(); it != G->nodes.end(); ++it)
        neurons[*it].dc = dc_mean + dc_std*random_normal();
}

void Neurons_network::set_dts(float dt)
{
    for(vector<Node>::iterator it = G->nodes.begin(); it != G->nodes.end(); ++it)
        neurons[*it].dt = dt;
}

void Neurons_network::set_syn_w_matrix(float type_prop, float syn_w_mean, float syn_w_std)
{
    size_t i = 0;
    for(vector<Link>::iterator it = G->links.begin(); it != G->links.end(); ++it)
    {
        neurons[*( (*it).from) ].syn_type = (i < type_prop*G->nodes.size())*2-1;

        float aux = MAX(syn_w_mean + syn_w_std*random_normal(),0);
        synapses[*it].weight = aux;

        i++;
    }
}

void Neurons_network::set_syn_d_matrix(float syn_d_mean, float syn_d_std)
{

    for(vector<Link>::iterator it = G->links.begin(); it != G->links.end(); ++it)
    {
        float aux = syn_d_mean + syn_d_std*random_normal();
        aux = floor( CLAMP(aux,0, neurons[*( (*it).to) ].sp_bufferSize  ) );
        synapses[*it].delay = aux;
    }

}

void Neurons_network::togg_syn_matrix()
{
    bool_syn_matrix = !bool_syn_matrix;
}

void Neurons_network::reset()
{
    for(vector<Node>::iterator it = G->nodes.begin(); it != G->nodes.end(); ++it)
        neurons[*it].reset();

}


float drand()   /* uniform distribution, (0..1] */
{    return (rand()+1.0)/(RAND_MAX+1.0);   }

float random_normal()  /* normal distribution, centered on 0, std dev 1 */
{    return sqrt(-2*log(drand())) * cos(2*M_PI*drand());    }

