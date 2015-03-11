#include "Neurons_network.h"

Neurons_network::Neurons_network(){

}

void Neurons_network::setup()
{

    bool_syn_matrix = true;
    neuron_id = 0;
    synapse_id = 0;
}

void Neurons_network::add_neuron(int num)
{
    for (size_t i=1;i<=num;i++)
    {
        Neuron* neuron = new Neuron;
        neuron->setup(neuron_id);
        neuron_id++;

        neurons.push_back(neuron);
    }

}

void Neurons_network::remove_neuron(size_t id)
{
    for(size_t i = 0 ; i < neurons.size();i++)
        if (neurons[i]->id==id)
            {
                neurons[i]=neurons.back();
                neurons.pop_back();
            }
}

void Neurons_network::remove_synapse(size_t id)
{
    for(size_t i=0; i<synapses.size(); i++)
    {
        if(synapses[i]->id == id)
        {
            synapses[i] = synapses.back();
            synapses.pop_back();
        }
    }
}

void Neurons_network::add_all_synapses()
{
    for(size_t i = 0 ; i < neurons.size();i++)
    {
        for(size_t j = 0 ; j < neurons.size();j++)
        {
            if (i!=j)
                add_synapse(i,j);
        }
    }
}

void Neurons_network::add_synapse(size_t source_id,size_t target_id )
{

    Synapse* synapse = new Synapse;

    for(size_t i = 0 ; i < neurons.size();i++)
    {
        if (neurons[i]->id==source_id)
            {
                synapse->from = neurons[i];
            }

        if (neurons[i]->id==target_id)
            {
                synapse->to = neurons[i];
            }
    }

    synapse->id = synapse_id;
    synapses.push_back(synapse );
    synapse_id++;

}

void Neurons_network::update()
{

    for(size_t i = 0; i < neurons.size(); i++)
        neurons[i]->update();

    if (bool_syn_matrix)
        for(size_t i = 0; i < synapses.size(); i++)
            synapses[i]->to->currentBuffer( synapses[i]->weight, synapses[i]->delay, synapses[i]->from );

}

Neuron* Neurons_network::neuronId(size_t id)
{
    Neuron* neuron;
    for(size_t i = 0; i < neurons.size(); i++)
    {
        if(id==neurons[i]->id)
            neuron = neurons[i];
    }

    return neuron;
}

Synapse* Neurons_network::synapseId(size_t id)
{
    Synapse* synapse;
    for(size_t i = 0; i < synapses.size(); i++)
    {
        if(id==synapses[i]->id)
            synapse = synapses[i];
    }

    return synapse;
}

void Neurons_network::draw()
{

}

void Neurons_network::set_currents(float dc_mean, float dc_std)
{
    for(size_t i = 0; i < neurons.size(); i++)
        neurons[i]->dc = dc_mean + dc_std*random_normal();
}

void Neurons_network::set_dts(float dt)
{
    for(size_t i = 0; i < neurons.size(); i++)
        neurons[i]->dt = dt;
}

void Neurons_network::set_syn_w_matrix(float type_prop, float syn_w_mean, float syn_w_std)
{
    for(size_t i = 0; i < synapses.size(); i++)
    {
        synapses[i]->from->syn_type = (i < type_prop*neurons.size())*2-1;

        float aux = MAX(syn_w_mean + syn_w_std*random_normal(),0);
        synapses[i]->weight = aux;
    }
}

void Neurons_network::set_syn_d_matrix(float syn_d_mean, float syn_d_std)
{

    for(size_t i = 0; i < synapses.size(); i++)
    {
        float aux = syn_d_mean + syn_d_std*random_normal();
        aux = floor( CLAMP(aux,0,synapses[i]->to->sp_bufferSize) );
        synapses[i]->delay = aux;
    }

}


void Neurons_network::togg_syn_matrix()
{
    bool_syn_matrix = !bool_syn_matrix;
}

void Neurons_network::reset()
{
    for(size_t i = 0; i < neurons.size(); i++){
        neurons[i]->reset();
    }
}



float drand()   /* uniform distribution, (0..1] */
{    return (rand()+1.0)/(RAND_MAX+1.0);   }

float random_normal()  /* normal distribution, centered on 0, std dev 1 */
{    return sqrt(-2*log(drand())) * cos(2*M_PI*drand());    }

