#include "stdio.h"
#include "NeuralNetwork.h"

int main(){
   NN network;
   if (nn_init(&network, 3, (int[]){1, 3, 1})) return 1;
   nn_predict(&network);
   nn_free(&network);
}