#include "Header.h"


int main()
{

	setlocale(LC_ALL, "rus");
	
	int row;
	int column;
	int** Arr;
	int errorcheck;
	errorcheck=ReadMatrix("matrix.txt", &Arr, &row, &column);
	switch (errorcheck)
	{
	case -1: 
	{
		printf("Ошибка открытия файла\n");
		return -1;
	}
	case -2:
	{
		printf("Ошибка считывания кол-ва строк\n");
		return -2;
	}
	case -3: 
	{
		printf("Обнаружен конец файла при считывании числа строк\n");
		return -3;
	}
	case -4:
	{
		printf("Ошибка считывания кол-ва столбцов\n");
		return -4;
	}
	case -5:
	{
		printf("Обнаружен конец файла при считывании числа столбцов\n");
		return -5;
	}
	case -6:
	{
		printf("Ошибка выделения динамической памяти!\n");
		return -6;
	}
	case -7:
	{
		printf("Ошибка выделения динамической памяти!\n");
		return -7;
	}
	case -8:
	{
		printf("Ошибка чтения матрицы");
		return -8;
	}
	case -9:
	{
		printf("в процессе считывания элементов преждевременно обнаружен конец файла\n");
		return -9;
	}
	default:
		printf("\nОшибок чтения не обнаружено\n");
		break;
	}

	SaddlePointSeek(Arr, row, column);

	return 0;
}