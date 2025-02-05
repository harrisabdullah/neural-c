#include <stdio.h>
#include "NeuralNetwork.h"

void nn_print(NN network) {
    printf("Neural Network Structure:\n");
    printf("Number of layers: %d\n", network.numLayers);

    printf("Nodes per layer: ");
    for (int i = 0; i < network.numLayers; i++) {
        printf("%d ", network.nodesPerLayer[i]);
    }
    printf("\n\n");

    for (int i = 0; i < network.numLayers; i++) {
        printf("Layer %d:\n", i);
        printf("  Activations: ");
        for (int j = 0; j < network.nodesPerLayer[i]; j++) {
            printf("%f ", network.activations[i][j]);
        }
        printf("\n");

        printf("  Weighted sums: ");
        for (int j = 0; j < network.nodesPerLayer[i]; j++) {
            printf("%f ", network.weightedSums[i][j]);
        }
        printf("\n");

        if (i > 0) {
            printf("  Biases: ");
            for (int j = 0; j < network.nodesPerLayer[i]; j++) {
                printf("%f ", network.biases[i-1][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    for (int i = 0; i < network.numLayers - 1; i++) {
        printf("Weights from layer %d to layer %d:\n", i, i+1);
        for (int j = 0; j < network.nodesPerLayer[i+1]; j++) {
            printf("  Weights for neuron %d in layer %d: ", j, i+1);
            for (int k = 0; k < network.nodesPerLayer[i]; k++) {
                printf("%f ", network.weights[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
