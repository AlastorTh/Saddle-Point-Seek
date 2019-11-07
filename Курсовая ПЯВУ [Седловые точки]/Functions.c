#include "Header.h"
#include <math.h>

int ReadMatrix(const char* inputFileName, int*** _Array, int* row_ptr, int* column_ptr)
{
	FILE* inputFile;
	inputFile = fopen(inputFileName, "rt");
	int i, j;



	if (inputFile != NULL)
	{
		if (fscanf(inputFile, "%d", row_ptr) != 1)
		{
			printf("Ошибка считывания кол-ва строк");
			return -2;
		}


		if (fscanf(inputFile, "%d", column_ptr) != 1)
		{
			printf("Ошибка считывания кол-ва столбцов");
			return -3;
		}





		printf("Число строк: %d\nЧисло столбцов: %d \n", *row_ptr, *column_ptr);

		*_Array = malloc((sizeof(int**)) * (*row_ptr));
		int** Array = *_Array;
		for (i = 0; i < *row_ptr; i++)
		{
			Array[i] = malloc(sizeof(int*) * (*column_ptr));
		}

		for (i = 0; i < *row_ptr; i++)
		{
			for (j = 0; j < *column_ptr; j++)
			{
				if (fscanf(inputFile, "%d", &Array[i][j]) != 1)
				{
					printf("Ошибка чтения матрицы");
					return -5;
				}


			}
		}
		printf("Результат чтения матрицы:\n");
		for (i = 0; i < *row_ptr; i++)
		{

			for (j = 0; j < *column_ptr; j++)
			{
				printf("%d ", Array[i][j]);
			}
			printf("\n");
		}



		fclose(inputFile);
	}
	else
	{
		perror("Ошибка чтения файла");
	}

	


	return 0;
}

int MinMaxRows(int** Array, int* row_ptr, int* column_ptr, int *MaxRowArr, int *MinRowArr) // нахождение минимумов и максимумов в строках
{
	int min;
	int max;
	
	int i;
	int j;
	for (i = 0; i < *row_ptr; i++)
	{
		j = 0;
		min = Array[i][j];
		max = Array[i][j];

		for (j = 0; j < *column_ptr; j++) // поиск максимумов и минимумов в строках 
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

int MinMaxColumns(int** Array, int* row_ptr, int* column_ptr, int* MaxColumnArr, int* MinColumnArr) // min/max в столбцах
{
	int min;
	int max;

	int i; 
	int j;

	for (j = 0; j < *column_ptr; j++) 
	{
		i = 0;
		min = Array[i][j];
		max = Array[i][j];
		for (i = 0; i < *row_ptr; i++) 
		{
			if (Array[i][j] >= max) // если тек. элемент больше макс
			{
				max = Array[i][j];
				MaxColumnArr [j] = Array[i][j];
			}
			if (Array[i][j] <= min) // текущий элемент меньше мин? 
			{
				min = Array[i][j];
				MinColumnArr[j] = Array[i][j];
			}
		}
	}


	

}

int SaddlePointSeek(int** Array, int* row_ptr, int* column_ptr) // поиск седловых точек
{

	printf("\n\n\n\n\n\n");

	int* MaxRowArr = (int*)malloc(sizeof(int*) * (*row_ptr));
	int* MinRowArr = (int*)malloc(sizeof(int*) * (*row_ptr));

	int* MaxColumnArr = (int*)malloc(sizeof(int*) * (*column_ptr));
	int* MinColumnArr = (int*)malloc(sizeof(int*) * (*column_ptr));

	MinMaxRows(Array, row_ptr, column_ptr, MaxRowArr, MinRowArr);
	MinMaxColumns(Array, row_ptr, column_ptr, MaxRowArr, MinRowArr);

	for (int i = 0; i < *row_ptr; i++) 
	{
		printf("%d\t", MaxRowArr[i]);
	}

	/*for (i = 0; i < *row_ptr; i++)
	{
		j = 0;
		min = Array[i][j];
		max = Array[i][j];

		for (j = 0; j <*column_ptr; j++) // поиск максимумов и минимумов в строках
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

	*/

	/*

		printf("\n");
		for (i = 0; i < *row_ptr; i++)
		{
			printf("%d  ", MaxRowArr[i]);
		}
		printf("\n\n\n\n");
		for (i = 0; i < *row_ptr; i++)
		{
			printf("%d  ", MinRowArr[i]);
		}

	*/
	return 0;
}