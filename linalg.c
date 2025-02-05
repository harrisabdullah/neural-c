
void la_mat_vect_mul(float** matrix, float* vector, float* output, int rows, int cols){
    for (int i = 0; i < rows; i++) {
        output[i] = 0.0f;
        for (int j = 0; j < cols; j++) {
            output[i] += matrix[i][j] * vector[j];
        }
    }
}

void la_vect_sum_inplace(float* dest, float* src, int cols){
   for (int i=0; i<cols; i++)
      dest[i] = dest[i] + src[i];
}
