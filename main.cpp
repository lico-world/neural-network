#include <iostream>
#include <chrono>

#include "lib/ANN_utils.h"

int main(int argc, char ** argv)
{
    auto start = std::chrono::high_resolution_clock::now();

    for(int i=0 ; i<1000000 ; i++)
    {
        ANN_utils::sigmoidTransferFunction((float)i);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;

    std::cout << "Execution time: " << duration.count() << " ms" << std::endl;

    return 0;
}