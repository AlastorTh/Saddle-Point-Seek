#include <stdio.h>
#include <stdlib.h>

int ReadMatrix(const char*, int ***Array, int *row_ptr, int *column_ptr);
int SaddlePointSeek(int** Array, int *, int *);
int MinMaxRows(int** Array, int*, int*);