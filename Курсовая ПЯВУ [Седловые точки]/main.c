#include "Header.h"


int main()
{

	setlocale(LC_ALL, "rus");
	
	int row;
	int column;
	int** Arr;
	ReadMatrix("matrix.txt", &Arr, &row, &column);
	SaddlePointSeek(Arr, row, column);

	return 0;
}