#include "../lib/ANN_utils.h"

namespace ANN_utils
{
    float sigmoidTransferFunction(float x)
    {
        return 1/(1+exp(-x));
    }
}