#include "../lib/network.h"

Network::Network(int nbInputs, int nbOutputs, int nbHiddenLayers, std::vector<int> hiddenLayersSizes) : _nbHiddenLayers(nbHiddenLayers), _nbInputs(nbInputs), _nbOutputs(nbOutputs)
{
    // Create the right amount of hidden layers
    for(auto s : hiddenLayersSizes)
    {
        this->_hiddenLayers.push_back(std::vector<Neuron*>(s));
        for(int i=0 ; i<s ; i++)
            this->_hiddenLayers[this->_hiddenLayers.size()-1][i] = new Neuron();
    }

    // Create input and output layers
    this->_inputLayer = std::vector<Neuron*>(this->_nbInputs);
    for(int i=0 ; i<this->_nbInputs ; i++)
        this->_inputLayer[i] = new Neuron();

    this->_outputLayer = std::vector<Neuron*>(this->_nbOutputs);
    for(int i=0 ; i<this->_nbOutputs ; i++)
        this->_outputLayer[i] = new Neuron();

    // Connects every layer to past outputs
    for(auto& n : this->_hiddenLayers[0])
        for(auto& n_1 : this->_inputLayer)
            n->addInput(n_1);

    for (unsigned int i = 0; i < this->_hiddenLayers.size() - 1; i++)
        for (auto& n : this->_hiddenLayers[i])
            for (auto& n_1 : this->_hiddenLayers[i + 1])
                n_1->addInput(n);

    for(auto& n : this->_outputLayer)
        for(auto& n__1 : this->_hiddenLayers[this->_hiddenLayers.size()-1])
        {
            n->addInput(n__1);
        }


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
        if(this->_inputLayer[i] != nullptr)
        {
            this->_inputLayer[i]->setBias(0);
            this->_inputLayer[i]->setOutput(data[i]);
        }

    // Compute layers one by one
    for(auto& layer : this->_hiddenLayers)
        for(auto& neuron : layer)
            if(neuron != nullptr)
                neuron->computeOutput();

    for(auto& output : this->_outputLayer)
        if(output != nullptr)
        {
            output->computeOutput();
            result.push_back(output->getOutput());
        }

    return result;
}

bool Network::backpropagation(std::vector<float> result, std::vector<float> wanted)
{
    if(result.size() != wanted.size())
    {
        std::cout << "The labeled data should have as many possibilities as the network result." << std::endl;
        return false;
    }

    for(int i=0 ; i<this->_outputLayer.size() ; i++)
    {
        this->_outputLayer[i]->setUnitError(result[i] * (1 - result[i]) * (wanted[i] - result[i]));
        this->_outputLayer[i]->updateWeights();
    }

    for(auto& l : this->_hiddenLayers)
        for(auto& n : l)
            n->updateWeights();

    return true;
}