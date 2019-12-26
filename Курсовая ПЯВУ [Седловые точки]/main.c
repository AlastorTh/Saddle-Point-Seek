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
		printf("������ �������� �����\n");
		return -1;
	}
	case -2:
	{
		printf("������ ���������� ���-�� �����\n");
		return -2;
	}
	case -3: 
	{
		printf("��������� ����� ����� ��� ���������� ����� �����\n");
		return -3;
	}
	case -4:
	{
		printf("������ ���������� ���-�� ��������\n");
		return -4;
	}
	case -5:
	{
		printf("��������� ����� ����� ��� ���������� ����� ��������\n");
		return -5;
	}
	case -6:
	{
		printf("������ ��������� ������������ ������!\n");
		return -6;
	}
	case -7:
	{
		printf("������ ��������� ������������ ������!\n");
		return -7;
	}
	case -8:
	{
		printf("������ ������ �������");
		return -8;
	}
	case -9:
	{
		printf("� �������� ���������� ��������� �������������� ��������� ����� �����\n");
		return -9;
	}
	default:
		printf("\n������ ������ �� ����������\n");
		break;
	}

	SaddlePointSeek(Arr, row, column);

	return 0;
}