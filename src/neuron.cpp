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

bool Neuron::updateWeights()
{
    return true;
}

bool Neuron::setGradient(float gradient)
{
    this->_gradient = gradient;
    return true;
}

bool Neuron::computeOutput()
{
    float out = this->_bias;

    for(unsigned int i=0 ; i<std::min(this->_weights.size(), this->_inputs.size()) ; i++)
        out += this->_weights[i] * this->_inputs[i].getOutput();

    this->_output = ANN_utils::sigmoidTransferFunction(out);

    return true;
}

float Neuron::getOutput()
{
    return this->_output;
}