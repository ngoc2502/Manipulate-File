#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
# include"stdio.h"
#pragma warning(disable:4996)

struct dtron
{
	int16_t x=0;
	int16_t y = 0;
	int16_t r = 0;
};

void createbin()
{
	int m = 3;
	FILE* fin = fopen("vdbin.bin", "wb");
	dtron a = { 1,1,2 };
	dtron b = { 0,0,2 };
	dtron c = { 2,2,4 };
	fwrite(&m,sizeof(m),1,fin);
	fwrite(&a, sizeof(struct dtron), 3, fin);
	fwrite(&b, sizeof(struct dtron), 3, fin);
	fwrite(&c, sizeof(struct dtron), 3, fin);
	fclose(fin);
}

void doc(char* path, dtron k[], int16_t &sl)
{
	FILE* fin = fopen(path, "rb");
	if (!fin)
	{
		printf ( "Error fin!");
		return;
	}
	int32_t m = 0;
	fread(&m, sizeof(m), 1, fin);
	for (int i = 0; i < m; i++)
	{
		fread(&k[i], sizeof(k[i]), 3, fin);
	}
	/*while (!feof(fin))
	{
		sl++;
		fread(&k[sl], sizeof(k[sl]), 3, fin);
	}*/
	fclose(fin);
}
int main()
{
	createbin();
	dtron k[10];
	int16_t sl = -1;
	char name[]= "vdbin.bin";
	doc(name, k,sl);
	for (int i = 0; i < 3; i++)
	{
		printf("%d %d %d\n", k[i].x, k[i].y, k[i].r);
	}
	return 0;
}
