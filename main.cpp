#include <iostream>
#include <chrono>

#include "lib/ANN_utils.h"
#include "lib/network.h"

int main(int argc, char ** argv)
{
    auto start = std::chrono::high_resolution_clock::now();

    Network N = Network(9, 2, 1, {4});

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;

    std::cout << "Execution time: " << duration.count() << " ms" << std::endl;

    return 0;
}