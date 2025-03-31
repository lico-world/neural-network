#include "../lib/network.h"

Network::Network(int nbInputs, int nbOutputs, int nbHiddenLayers, std::vector<int> hiddenLayersSizes) : _nbHiddenLayers(nbHiddenLayers), _nbInputs(nbInputs), _nbOutputs(nbOutputs)
{
    // Create the right amount of hidden layers
    for(auto s : hiddenLayersSizes)
        this->_hiddenLayers.push_back(std::vector<Neuron>(s));

    // Create input and output layers
    this->_inputLayer = std::vector<Neuron>(this->_nbInputs);
    this->_outputLayer = std::vector<Neuron>(this->_nbOutputs);

    // Connects every layer to past outputs
    for (int i = 0; i < this->_hiddenLayers.size() - 1; ++i)
        for (auto& n : this->_hiddenLayers[i])
            for (auto& n_1 : this->_hiddenLayers[i + 1])
                n_1.addInput(n);

    for(auto& n : this->_outputLayer)
        for(auto& n__1 : this->_hiddenLayers[this->_hiddenLayers.size()-1])
            n.addInput(n__1);
}

std::vector<float> Neuron::run(std::vector<float> data)
{
    return {};
}

bool Neuron::backpropagation()
{
    return true;
}