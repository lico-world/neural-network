#ifndef NEURAL_NETWORK_NETWORK_H
#define NEURAL_NETWORK_NETWORK_H

#include <iostream>

#include "neuron.h"

class Network {
private:
    unsigned int _nbHiddenLayers, _nbInputs, _nbOutputs;
    std::vector<std::vector<Neuron>> _hiddenLayers;
    std::vector<Neuron> _inputLayer, _outputLayer;

public:
    Network(int nbInputs, int nbOutputs, int nbHiddenLayers, std::vector<int> hiddenLayersSizes);

    std::vector<float> run(std::vector<float> data);
    bool backpropagation();
};


#endif //NEURAL_NETWORK_NETWORK_H
