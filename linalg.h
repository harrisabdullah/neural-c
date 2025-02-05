//
// Created by Harris on 5/02/25.
//

#ifndef linalg_h
#define linalg_h

void la_mat_vect_mul(float** matrix, float* vector, float* output, int rows, int col);
void la_vect_sum_inplace(float* dest, float* src, int cols);

#endif