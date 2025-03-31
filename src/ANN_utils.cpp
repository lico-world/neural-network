#include "../lib/ANN_utils.h"

namespace ANN_utils
{
    float sigmoidTransferFunction(float x)
    {
        return 1 / (1+exp(-x));
    }

    float derivativeSigmoidTransferFunction(float x)
    {
        return exp(-x) / ( pow((exp(-x)+1), 2) );
    }

    float randomNormalValue(float mean, float dev)
    {
        static std::mt19937 gen(static_cast<unsigned int>(
                                        std::chrono::steady_clock::now().time_since_epoch().count()
                                ));  // Use high-resolution time as a seed

        std::normal_distribution<float> dist(mean, dev);
        return dist(gen);
    }

    float randomUniformValue(float min, float max)
    {
        static std::mt19937 gen(static_cast<unsigned int>(
                                        std::chrono::steady_clock::now().time_since_epoch().count()
                                ));  // Use high-resolution time as a seed

        std::uniform_real_distribution<float> dist(min, max);
        return dist(gen);
    }
}