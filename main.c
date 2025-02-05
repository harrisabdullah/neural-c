#include "stdio.h"
#include "NeuralNetwork.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
   srand(time(NULL)); // setting the random seed to the currant time
   NN network;
   if (nn_init(&network, 3, (int[]){1, 3, 1})) return 1;
   network.activations[0][0] = 0.75f;
   nn_predict(&network);
   nn_print(network);
   nn_free(&network);
}