#include "Header.h"
#include <math.h>

int ReadMatrix(const char* inputFileName, int*** _Array, int* row_ptr, int* column_ptr)
{
	FILE* inputFile;
	inputFile = fopen(inputFileName, "rt");
	int i, j;

	
	
	/*for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 20; j++)
		*(Array + i * COLUMN_MAX + j) = i * j + 1;
	}

	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 20; j++) printf(" %4d", *(Array + i * COLUMN_MAX + j));
		printf("\n");
	}
	*/

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

		



		printf("%d  %d \n", *row_ptr, *column_ptr);

		*_Array = malloc(sizeof(**_Array)*(*row_ptr));
		int** Array = *_Array;
		for (int i = 0; i < *row_ptr; i++) 
		{
			Array[i] = malloc(sizeof(int) * (*column_ptr));
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

int SaddlePointSeek(int** Array, int* row_ptr, int* column_ptr)
{
	
	printf("\n\n\n\n\n\n");
	//for (i = 0; i < *row_ptr; i++)
	//{
	//	max = *(Array + i * COLUMN_MAX);
	//	for (j = 0; j < *column_ptr; j++)
	//	{
	//		CurElement = *(Array + i * COLUMN_MAX + j);
	//		
	//		if (CurElement >= max)
	//		{
	//			test_element = CurElement;
	//			column_test = j;
	//			//int* test_ptr = &column_test;
	//		}
	//		min = *(Array + column_test);
	//		
	//		for (k = 0; k < *row_ptr; k++)
	//		{
	//			ElementTest = *(Array + k * COLUMN_MAX + column_test);
	//			if (ElementTest< min)
	//			{
	//				row_saddle = k;
	//				column_saddle = column_test;
	//				printf("arr[%d][%d] = %d\t", row_saddle, column_saddle,*(Array + row_saddle * COLUMN_MAX + column_saddle));
	//				
	//			}
	//		}
	
	int *arr_max_row=malloc(sizeof(int)*(*row_ptr));
	int max;
	int min;
	int *arr_min_column =malloc(sizeof(int)*(*column_ptr));
	int i;
	int j;
	int inf = 2147483648;

	for (i = 0; i < *row_ptr; i++) 
	{
		j = 0;
		min = Array[i][j];
		max = Array[i][j];
		
		for (j = 0; j <*column_ptr; j++) // поиск максимумов и минимумов в строках 
		{
			if (Array[i][j] >= max) // если тек. элемент больше макс
			{
				max = Array[i][j];
				arr_max_row[i] = Array[i][j];
			}
			if (Array[i][j] <= min) // текущий элемент меньше мин? 
			{
				min = Array[i][j];
				arr_min_column [i] = Array[i][j];
			}
			


		}
		
	}

		printf("\n");
		for (i = 0; i < *row_ptr; i++) 
		{
			printf("%d  ", arr_max_row[i]);
		}
		for (i = 0; i < *column_ptr; i++)
		{
			printf("%d  ", arr_min_column[i]);
		}
	
	/*for (i = 0; i < *row_ptr; i++)
	{
		max = *Array + i;
		for (j = 0; j < *column_ptr; j++)
		{
			if (*(Array + i * COLUMN_MAX + j) > max)
			{
				max = *(Array + i * COLUMN_MAX + j);
				max_Arr[i] = *(Array + i * COLUMN_MAX + j);

			}

		}


	}
	*/
	return 0;
}