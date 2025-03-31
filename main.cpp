#include <iostream>
#include <chrono>

#include "lib/ANN_utils.h"
#include "lib/network.h"

int main(int argc, char ** argv)
{
    auto start = std::chrono::high_resolution_clock::now();

    Network N = Network(28*28, 10, 2, {16, 16});

    auto data = std::vector<float>(28*28);
    for(auto& d : data)
        d = ANN_utils::randomUniformValue(0.0f, 0.1f);

    auto wanted = std::vector<float>(10);
    for(auto& w : wanted)
        w = ANN_utils::randomUniformValue(0.0f, 0.1f);

    std::vector<float> result = N.run(data);

    for(int r=0 ; r<result.size() ; r++)
        std::cout << std::fixed << std::setprecision(3) << "Result class -" << r << "-: " << result[r] << std::endl;

    N.backpropagation(result, wanted);
    std::cout << std::endl;

    result = N.run(data);

    for(int r=0 ; r<result.size() ; r++)
        std::cout << std::fixed << std::setprecision(3) << "Result class -" << r << "-: " << result[r] << std::endl;

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;

    std::cout << "Execution time: " << duration.count() << " ms" << std::endl;

    return 0;
}