//
// Created by Harris on 29/01/25.
//

#ifndef NeuralNetwork_H
#define NeuralNetwork_H

typedef struct NeuralNetwork{
   int numLayers;
   int* nodesPerLayer;
   float** biases;
   float** activations;
   float** weightedSums;
   float*** weights;
} NN;

int nn_init(NN* network, int numLayers, int* nodesPerLayer);
void nn_free(NN* network);

void nn_predict(NN* network);
void nn_backpropagate(NN* network, float** activations, float* target, float* cache);

// debug
void nn_print(NN network);

#endif