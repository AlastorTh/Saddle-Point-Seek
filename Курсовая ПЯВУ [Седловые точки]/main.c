#include "Header.h"
#define ROW_MAX 20
#define COLUMN_MAX 20
#include <locale.h>

int main()
{

	setlocale(LC_ALL, "rus");
	
	int row;
	int column;
	int** Arr;
	//int Arr[ROW_MAX][COLUMN_MAX] = { 0 };
	ReadMatrix("matrix.txt", &Arr, &row, &column);
	SaddlePointSeek(Arr, &row, &column);

	return 0;
}