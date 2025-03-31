#ifndef NEURAL_NETWORK_NEURON_H
#define NEURAL_NETWORK_NEURON_H

#include <vector>
#include <random>
#include <iostream>
#include <iomanip>
#include <cstdlib>

#include "ANN_utils.h"

class Neuron {
private:
    float _bias, _gradient, _output;
    std::vector<float> _weights;
    std::vector<Neuron*> _inputs;

public:
    Neuron();

    float getOutput();
    bool computeOutput();
    bool setBias(float b);
    bool setOutput(float b); // For input neurons only
    bool addInput(Neuron* input);
    bool updateWeights();
    bool setGradient(float gradient);

    friend std::ostream& operator<<(std::ostream& os, const Neuron& n)
    {
        os << "Bias: " << n._bias << " - Output: " << n._output << " - Weights: ";
        for(auto& w : n._weights)
            std::cout << w << "  ";
        std::cout << " | " << n._inputs.size() << std::endl;
        return os;
    }
};


#endif //NEURAL_NETWORK_NEURON_H
