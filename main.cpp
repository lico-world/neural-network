#include <iostream>
#include <chrono>

#include "lib/ANN_utils.h"
#include "lib/network.h"

int main(int argc, char ** argv)
{
    auto start = std::chrono::high_resolution_clock::now();

    Network N = Network(9, 2, 2, {16, 16});

    auto data = std::vector<float>(9);
    for(auto& d : data)
        d = ANN_utils::randomUniformValue(0.0f, 0.1f);

    std::cout << "---DATA---" << std::endl;
    for(auto& d : data)
        std::cout << d << "  ";
    std::cout << std::endl;

    std::cout << "---NETWORK---" << std::endl;

    std::vector<float> result = N.run(data);
    std::cout << N;

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;

    std::cout << "Execution time: " << duration.count() << " ms" << std::endl;

    return 0;
}