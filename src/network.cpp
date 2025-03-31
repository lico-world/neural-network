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
    for (unsigned int i = 0; i < this->_hiddenLayers.size() - 1; ++i)
        for (auto& n : this->_hiddenLayers[i])
            for (auto& n_1 : this->_hiddenLayers[i + 1])
                n_1.addInput(n);

    for(auto& n : this->_outputLayer)
        for(auto& n__1 : this->_hiddenLayers[this->_hiddenLayers.size()-1])
            n.addInput(n__1);
}

std::vector<float> Network::run(std::vector<float> data)
{
    if(data.size() != this->_nbInputs)
    {
        std::cout << "Data size must me adapted to the inputs dimensions of the network: " << this->_nbInputs << std::endl;
        return {};
    }

    auto result = std::vector<float>(0);

    // Assign data to inputs
    for(unsigned int i=0 ; i<this->_nbInputs ; i++)
        this->_inputLayer[i].setBias(data[i]);

    // Compute layers one by one
    for(auto& layer : this->_hiddenLayers)
        for(auto& neuron : layer)
            neuron.computeOutput();

    for(auto& output : this->_outputLayer)
        result.push_back(output.computeOutput());

    return result;
}

bool Network::backpropagation()
{
    return true;
}