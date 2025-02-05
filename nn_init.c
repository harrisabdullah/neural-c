#include "NeuralNetwork.h"
#include <stdlib.h>
#include <string.h>


float randFloat(float min, float max){
   return min + (max - min) * ((float)rand() / RAND_MAX);
}

int nn_init(NN* network, int numLayers, int* nodesPerLayer){
   network->weightedSums = malloc(sizeof(float *) * numLayers);
   network->activations = malloc(sizeof(float *) * numLayers);
   network->biases = malloc(sizeof(float) * (numLayers-1));
   network->weights = malloc(sizeof(float **) * (numLayers-1));
   if (!network->weightedSums || !network->activations || !network->weights || !network->biases)
      return 1;

   for (int i=0; i<numLayers; i++){
      network->weightedSums[i] = malloc(sizeof(float) * nodesPerLayer[i]);
      network->activations[i] = malloc(sizeof(float) * nodesPerLayer[i]);
      if (!network->weightedSums[i] || !network->activations[i]) return 1;
   }
   for (int i=0; i<numLayers-1; i++){
      network->biases[i] = malloc(sizeof(float *) * nodesPerLayer[i+1]);
      network->weights[i] = malloc(sizeof(float *) * nodesPerLayer[i+1]);
      if (!network->weights[i] || !network->biases[i]) return 1;
      for (int j=0; j<nodesPerLayer[i+1]; j++){
         network->biases[i][j] = 0.0f;
         network->weights[i][j] = malloc(sizeof(float) * nodesPerLayer[i]);
         if (!network->weights[i][j]) return 1;
         for (int k=0; k<nodesPerLayer[i]; k++){
            network->weights[i][j][k] = randFloat(-0.5, 0.5);
         }
      }
   }
   network->nodesPerLayer = malloc(sizeof(int) * numLayers);
   if (!network->nodesPerLayer) return 1;
   memcpy(network->nodesPerLayer, nodesPerLayer, sizeof(int) * numLayers);
   network->numLayers = numLayers;
   return 0;
}