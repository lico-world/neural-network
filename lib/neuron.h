#ifndef NEURAL_NETWORK_NEURON_H
#define NEURAL_NETWORK_NEURON_H

#include <vector>

#include "ANN_utils.h"

class Neuron {
private:
    float _bias, _output;
    std::vector<float> _weights;
    std::vector<Neuron> _inputs;

public:
    Neuron();

    float getOutput();
    bool setBias(float b);
    bool addInput(Neuron input);
};


#endif //NEURAL_NETWORK_NEURON_H
