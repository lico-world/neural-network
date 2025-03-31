cmake_minimum_required(VERSION 3.10)

# Nom du projet
project(NeuralNetwork)

# Définir le standard C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Ajouter les répertoires d'en-têtes
include_directories(lib)

# Ajouter les fichiers source et d'en-tête
set(SOURCES
        src/neuron.cpp
        src/ANN_utils.cpp
        src/network.cpp
        main.cpp
)

set(HEADERS
        lib/neuron.h
        lib/ANN_utils.h
        lib/network.h
)

# Création de l'exécutable
add_executable(NeuralNetwork ${SOURCES} ${HEADERS})

# Options de compilation (ajustables selon le compilateur)
if (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(NeuralNetwork PRIVATE -Wall -Wextra -Wpedantic)
endif()
