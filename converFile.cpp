#include<iostream>
# include"stdio.h"
#pragma warning(disable:4996)
#pragma once

using namespace std;

void converTextToBin(char textName[], char binName[])
{
	int m = 0, n = 0;
	FILE* ft = fopen(textName, "r+");
	FILE* fb = fopen(binName, "wb+");
	if (!ft)
	{
		printf("Error ft");
		return;
	}
	if (!fb)
	{
		printf("Error fb");
		return;
	}
	fscanf(ft,"%d",&m);
	fscanf(ft,"%d",&n);
	int ** arr = new int * [m];
	for (int i = 0; i < m; i++)
	{
		arr[i] = new int [n];
	}
	for (int i=0;i<m;i++)
		for (int j = 0; j < n; j++)
		{
			fscanf(ft,"%d",&arr[i][j]);
		}
	fwrite(&m, sizeof(m), 1, fb);
	fwrite(&n, sizeof(n), 1, fb);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			fwrite(&arr[i][j], sizeof(arr[i][j]), 1, fb);
		}
	fclose(ft);
	fclose(fb);
	for (int i = 0; i < m; i++)
	{
		delete[]arr[i];
	}
	delete[]arr;
	arr = nullptr;
}
void converBinToText(char textName[], char binName[])
{
	int m = 0, n = 0;
	FILE* ft = fopen(textName, "w+");
	FILE* fb = fopen(binName, "rb+");
	fread(&m, sizeof(m), 1, fb);
	fread(&n, sizeof(n), 1, fb);
	int** arr = new int * [m];
	for (int i = 0; i < m; i++)
	{
		arr[i] = new int [n];
	}
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			fread(&arr[i][j], sizeof(arr[i][j]), 1, fb);
		}
	fprintf(ft, "%d %d \n", m, n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			fprintf(ft, "%d ", arr[i][j]);
		}
		fprintf(ft, "\n");
	}
	fclose(ft);
	fclose(fb);
	for (int i = 0; i < m; i++)
	{
		delete[]arr[i];
	}
	delete[]arr;
	arr = nullptr;
}
int main()
{
	char tName[]="bai2In.txt";
	char bName[] = "bai2Out.bin";
	char kq[] = "bai2Outtext.txt";
	converTextToBin(tName, bName);
	converBinToText(kq, bName);
	return 0;
}