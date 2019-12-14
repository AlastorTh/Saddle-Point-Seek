#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int ReadMatrix(const char*, int ***Array, int *row_ptr, int *column_ptr);
int SaddlePointSeek(int** Array, int row_ptr, int column_ptr );
int MinMaxRows(int** Array, int row_ptr, int column_ptr, int* MaxRowArr, int* MinRowArr);
int MinMaxColumns(int** Array, int row_ptr, int column_ptr, int* MaxColumnArr , int* MinColumnArr);