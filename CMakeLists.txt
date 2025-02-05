cmake_minimum_required(VERSION 3.23)
project(neural C)

set(CMAKE_C_STANDARD 99)

# Set the source files for the project
set(SOURCES
    main.c
    linalg.c
    nn_init.c
    nn_free.c
    nn_predict.c
)

set(HEADERS
    NeuralNetwork.h
    linalg.h
)

# Add executable target
add_executable(neural ${PROJECT_SOURCE_DIR}/${SOURCES} ${PROJECT_SOURCE_DIR}/${HEADERS})
