#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int reduce(int **two_array, const char *func, int N, int M) {
    int result;
    if (strcmp(func, "max") == 0) {
        result = two_array[0][0];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (two_array[i][j] > result) {
                    result = two_array[i][j];
                }
            }
        }
    } else if (strcmp(func, "min") == 0) {
        result = two_array[0][0];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (two_array[i][j] < result) {
                    result = two_array[i][j];
                }
            }
        }
    } else if (strcmp(func, "sum") == 0) {
        result = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                result += two_array[i][j];
            }
        }
    } else {
        // Invalid function
        printf("Invalid function\n");
        result = 0;
    }
    return result;
}

int *reduce_with_axis(int **two_array, const char *func, int N, int M, int axis) {
    int *result;
    if (axis == 0) {
        result = malloc(M * sizeof(int));
        for (int j = 0; j < M; j++) {
            if (strcmp(func, "max") == 0) {
                result[j] = two_array[0][j];
                for (int i = 0; i < N; i++) {
                    if (two_array[i][j] > result[j]) {
                        result[j] = two_array[i][j];
                    }
                }
            } else if (strcmp(func, "min") == 0) {
                result[j] = two_array[0][j];
                for (int i = 0; i < N; i++) {
                    if (two_array[i][j] < result[j]) {
                        result[j] = two_array[i][j];
                    }
                }
            } else if (strcmp(func, "sum") == 0) {
                result[j] = 0;
                for (int i = 0; i < N; i++) {
                    result[j] += two_array[i][j];
                }
            } else {
                // Invalid function
                printf("Invalid function\n");
                free(result);
                result = NULL;
                break;
            }
        }
    } else if (axis == 1) {
        result = malloc(N * sizeof(int));
        for (int i = 0; i < N; i++) {
            if (strcmp(func, "max") == 0) {
                result[i] = two_array[i][0];
                for (int j = 0; j < M; j++) {
                    if (two_array[i][j] > result[i]) {
                        result[i] = two_array[i][j];
                    }
                }
            } else if (strcmp(func, "min") == 0) {
                result[i] = two_array[i][0];
                for (int j = 0; j < M; j++) {
                    if (two_array[i][j] < result[i]) {
                        result[i] = two_array[i][j];
                    }
                }
            } else if (strcmp(func, "sum") == 0) {
                result[i] = 0;
                for (int j = 0; j < M; j++) {
                    result[i] += two_array[i][j];
                }
            } else {
                // Invalid function
                printf("Invalid function\n");
                free(result);
                result = NULL;
                break;
            }
        }
    } else {
        // Invalid axis
        printf("Invalid axis\n");
        result = NULL;
    }
    return result;
}

int **transpose(int **two_array, int N, int M) {
    int **result = malloc(M * sizeof(int *));
    for (int i = 0; i < M; i++) {
        result[i] = malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) {
            result[i][j] = two_array[j][i];
        }
    }
    return result;
}

int main() {
    srand(time(NULL));

    int N = 3, M = 4;
    int **two_array = malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        two_array[i] = malloc(M * sizeof(int));
        for (int j = 0; j < M; j++) {
            two_array[i][j] = rand() % 10;
            printf("array[%d][%d] = %d\n", i, j, two_array[i][j]);
        }
    }

    int reduced = reduce(two_array, "max", N, M);
    printf("Max element: %d\n", reduced);

    int *reduced_axis = reduce_with_axis(two_array, "max", N, M, 1);
    printf("Max elements along axis 1: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", reduced_axis[i]);
    }
    printf("\n");
    free(reduced_axis);

    int **transposed_array = transpose(two_array, N, M);
    printf("Transposed array:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", transposed_array[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < N; i++) {
        free(two_array[i]);
    }
    free(two_array);

    for (int i = 0; i < M; i++) {
        free(transposed_array[i]);
    }
    free(transposed_array);

    return 0;
}
