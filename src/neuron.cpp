#include "../lib/neuron.h"

Neuron::Neuron()
{
    this->_bias = ANN_utils::randomNormalValue(0.0f, 1.0f);
    this->_weights = std::vector<float>();
    this->_inputs = std::vector<Neuron*>();
}

bool Neuron::setBias(float b)
{
    this->_bias = b;
    return true;
}

bool Neuron::setOutput(float o)
{
    this->_output = o;
    return true;
}

bool Neuron::addInput(Neuron* input)
{
    if(input == nullptr)
        return false;

    this->_inputs.push_back(input);
    this->_weights.push_back(ANN_utils::randomNormalValue(0.0f, 1.0f));
    return true;
}

bool Neuron::updateWeights()
{
    for(int i=0 ; i<this->_inputs.size() ; i++)
    {
        this->_inputs[i]->setUnitError(this->_weights[i] * this->_unitError);
        this->_weights[i] += this->_unitError * this->_inputs[i]->getOutput();
    }

    return true;
}

bool Neuron::setUnitError(float unitError)
{
    this->_unitError = unitError;
    return true;
}

bool Neuron::computeOutput()
{
    float out = this->_bias;

    for(unsigned int i=0 ; i<std::min(this->_weights.size(), this->_inputs.size()) ; i++)
        out += this->_weights[i] * this->_inputs[i]->getOutput();

    this->_output = ANN_utils::sigmoidTransferFunction(out);

    return true;
}

float Neuron::getOutput()
{
    return this->_output;
}