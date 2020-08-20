#pragma warning(disable:4996)
#include<iostream>
#include"stdio.h"
using namespace std;

int main()
{
	FILE* fin = nullptr;
	int a[10];
	int x = 0;
	int z = 0;
	int y = 0;
	fin=fopen("inputvd.txt", "r");
	if (!fin)
	{
		printf("error !");
		return -1;
	}
	fscanf(fin, "%d", &x);
	for (int i = 0; i < x; i++)
		fscanf(fin, "%d ", &a[i]);
	printf("%d\n", x);
	for (int i=0;i<x;i++)
	printf("%d ",a[i]);
	FILE* fout = nullptr;


	fout = fopen("output.txt", "w");
	if (!fout)
	{
		printf("Error opening!");
		return -1;
	}
	fprintf(fout, "%d\n", x);
	for (int i = 0; i < x; i++)
		fprintf(fout,"%d ", a[i]);


	fclose(fout);
	fclose(fin);
	return 0;
}
