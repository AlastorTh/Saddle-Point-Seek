#include "Header.h"

int ReadMatrix(const char* inputFileName, int*** _Array, int* row_ptr, int* column_ptr)
{
	FILE* inputFile;
	inputFile = fopen(inputFileName, "rt");
	int i, j;
	int check;



	if (inputFile == NULL)
	{
		return -1;
	}

	check = fscanf(inputFile, "%d", row_ptr);
	if (check==0)
	{
		return -2;
	}
	if (check == EOF) 
	{
		return -3;
	}


	check = fscanf(inputFile, "%d", column_ptr);
	if (check == 0)
	{
		return -4;
	}

	if (check == EOF)
	{
		return -5;
	}



	printf("Число строк: %d\nЧисло столбцов: %d \n\n", *row_ptr, *column_ptr);

	*_Array = malloc((sizeof(int**)) * (*row_ptr));
	if (*_Array == NULL)
	{
		return -6;
	}
	int** Array = *_Array;
	for (i = 0; i < *row_ptr; ++i)
	{
		Array[i] = malloc(sizeof(int*) * (*column_ptr));
		if (Array[i] == NULL)
		{
			return -7;
		}
	}

	for (i = 0; i < *row_ptr; ++i)
	{
		for (j = 0; j < *column_ptr; ++j)
		{
			check = fscanf(inputFile, "%d", &Array[i][j]);
			if (check == 0)
			{
				return -8;
			}

			if (check == EOF)
			{
				return -9;
			}

		}
	}
	printf("Результат чтения матрицы:\n");
	for (i = 0; i < *row_ptr; ++i)
	{

		for (j = 0; j < *column_ptr; ++j)
		{
			printf("%d ", Array[i][j]);
		}
		printf("\n");
	}



	fclose(inputFile);






	return 0;
}

int SaddlePointSeek(int** Array, int row_ptr, int column_ptr) // поиск седловых точек
{

	printf("\n\n\n\n");
	int i;
	int j;
	int counter;

	int* MaxRowArr = (int*)malloc(sizeof(int*) * (row_ptr));
	int* MinRowArr = (int*)malloc(sizeof(int*) * (row_ptr));

	int* MaxColumnArr = (int*)malloc(sizeof(int*) * (column_ptr));
	int* MinColumnArr = (int*)malloc(sizeof(int*) * (column_ptr));

	MinMaxRows(Array, row_ptr, column_ptr, MaxRowArr, MinRowArr);
	MinMaxColumns(Array, row_ptr, column_ptr, MaxColumnArr, MinColumnArr);


	for (i = 0; i < row_ptr; ++i)
	{
		for (j = 0; j < column_ptr; ++j)
		{


			if (MaxRowArr[i] == MinColumnArr[j])
			{
				printf("Седловая точка: [%d] [%d] %d\n", i, j, MaxRowArr[i]);
			}
			if (MinRowArr[i] == MaxColumnArr[j])
			{
				printf("Седловая точка: [%d] [%d] %d\n", i, j, MinRowArr[i]);
			}
		}
	}
	return 0;
}



int MinMaxRows(int** Array, int row_ptr, int column_ptr, int* MaxRowArr, int* MinRowArr) // нахождение минимумов и максимумов в строках
{
	int min;
	int max;

	int i;
	int j;
	for (i = 0; i < row_ptr; ++i)
	{
		j = 0;
		min = Array[i][j];
		max = Array[i][j];

		for (j = 0; j < column_ptr; ++j) // поиск максимумов и минимумов в строках 
		{
			if (Array[i][j] >= max) // если тек. элемент больше макс
			{
				max = Array[i][j];
				MaxRowArr[i] = Array[i][j];
			}
			if (Array[i][j] <= min) // текущий элемент меньше мин? 
			{
				min = Array[i][j];
				MinRowArr[i] = Array[i][j];
			}



		}

	}




	return 0;
}

int MinMaxColumns(int** Array, int row_ptr, int column_ptr, int* MaxColumnArr, int* MinColumnArr) // min/max в столбцах
{
	int min;
	int max;

	int i;
	int j;

	for (j = 0; j < column_ptr; ++j)
	{
		i = 0;
		min = Array[i][j];
		max = Array[i][j];
		for (i = 0; i < row_ptr; ++i)
		{
			if (Array[i][j] >= max) // если тек. элемент больше макс
			{
				max = Array[i][j];
				MaxColumnArr[j] = Array[i][j];
			}
			if (Array[i][j] <= min) // текущий элемент меньше мин? 
			{
				min = Array[i][j];
				MinColumnArr[j] = Array[i][j];
			}
		}
	}




}

