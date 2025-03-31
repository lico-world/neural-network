#ifndef NEURAL_NETWORK_ANN_UTILS_H
#define NEURAL_NETWORK_ANN_UTILS_H

#include <vector>
#include <cmath>
#include <random>
#include <chrono>

namespace ANN_utils {
    float sigmoidTransferFunction(float x);
    float derivativeSigmoidTransferFunction(float x);

    float randomUniformValue(float min, float max);
    float randomNormalValue(float mean, float dev);
}


#endif //NEURAL_NETWORK_ANN_UTILS_H
