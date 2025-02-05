#include "NeuralNetwork.h"
#include <stdlib.h>

void nn_free(NN* network) {
    for (int i = 0; i < network->numLayers - 1; i++) {
         for (int j = 0; j < network->nodesPerLayer[i + 1]; j++) {
            free(network->weights[i][j]);
        }
         free(network->weights[i]);
         free(network->biases[i]);  
    }
    free(network->weights);
    free(network->biases);
    
    for (int i = 0; i < network->numLayers; i++) {
        free(network->weightedSums[i]);
        free(network->activations[i]);
    }

    free(network->weightedSums);
    free(network->activations);
    free(network->nodesPerLayer);
}