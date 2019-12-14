#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int ReadMatrix(const char*, int ***Array, int *row_ptr, int *column_ptr);
int SaddlePointSeek(int** Array, int *, int *);
int MinMaxRows(int** Array, int*, int*, int*, int*);
int MinMaxColumns(int** Array, int*, int*, int*, int*);