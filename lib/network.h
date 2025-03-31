#ifndef NEURAL_NETWORK_NETWORK_H
#define NEURAL_NETWORK_NETWORK_H

#include <iostream>

#include "neuron.h"

class Network {
private:
    unsigned int _nbHiddenLayers, _nbInputs, _nbOutputs;
    std::vector<std::vector<Neuron*>> _hiddenLayers;
    std::vector<Neuron*> _inputLayer, _outputLayer;

public:
    Network(int nbInputs, int nbOutputs, int nbHiddenLayers, std::vector<int> hiddenLayersSizes);

    std::vector<float> run(std::vector<float> data);
    bool backpropagation(std::vector<float> result, std::vector<float> wanted);

    friend std::ostream& operator<<(std::ostream& os, const Network& n)
    {
        std::cout << std::fixed << std::setprecision(3) << "INPUTS" << std::endl;
        for(auto& neuron : n._inputLayer)
            std::cout << *neuron;
        std::cout << std::endl;

        std::cout << "HIDDEN LAYERS [" << n._nbHiddenLayers << "]" << std::endl;
        for(auto& l : n._hiddenLayers)
        {
            for(auto& neuron : l)
                if(neuron != nullptr)
                    std::cout << *neuron;
                else
                    std::cout << "NULL.";
            std::cout << std::endl;
        }

        std::cout << "OUTPUTS" << std::endl;
        for(auto& neuron : n._outputLayer)
            std::cout << *neuron;
        std::cout << std::endl;

        return os;
    }
};


#endif //NEURAL_NETWORK_NETWORK_H
