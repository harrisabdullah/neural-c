#include "NeuralNetwork.h"
#include "linalg.h"

float relu(float x) {
   return (x > 0) ? x : 0;
}

float relu_derivative(float x) {
    return (x > 0) ? 1.0f : 0.0f;
}

void nn_predict(NN* network){
   for (int i=0; i<network->numLayers-1; i++){
      la_mat_vect_mul(network->weights[i], network->activations[i], network->weightedSums[i+1], 
                        network->nodesPerLayer[i+1], network->nodesPerLayer[i]);
      la_vect_sum_inplace(network->weightedSums[i+1], network->biases[i], network->nodesPerLayer[i+1]);
      for (int j=0; j<network->nodesPerLayer[i+1]; j++){
         network->activations[i+1][j] = relu(network->weightedSums[i+1][j]);
      }
   }
}
