#include "../lib/neuron.h"

Neuron::Neuron() : _bias(1)
{
    this->_weights = std::vector<float>();
    this->_inputs = std::vector<Neuron>();
}

bool Neuron::setBias(float b)
{
    this->_bias = b;
    return true;
}

bool Neuron::addInput(Neuron input)
{
    this->_inputs.push_back(input);
    this->_weights.push_back(1);
    return true;
}

bool Neuron::setWeights(std::vector<float> newWeights)
{
    this->_weights = newWeights;
    return true;
}

float Neuron::getOutput()
{
    float output = this->_bias;

    for(unsigned int i=0 ; i<std::min(this->_weights.size(), this->_inputs.size()) ; i++)
        output += this->_weights[i] * this->_inputs[i].getOutput();

    return ANN_utils::sigmoidTransferFunction(output);
}