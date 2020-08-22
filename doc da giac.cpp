#pragma warning(disable:4996)
#include<iostream>
#include<cstdint>
#include<stdio.h>

struct Node
{
	int num = 0;
	int th = 0;
	Node* pnext = nullptr;
};
struct Point
{
	int x = 0;
	int y = 0;
};
/*struct degiac
{
	Point* p[];
};*/
int tongsoNguyen(char* s)
{
	int i = 0;
	int sum = 0;
	while (s[i] != '\0')
	{
		int num = -1;
		while (s[i] >= '0' && s[i] <= '9')
		{
			if (num == -1)
				num = 0;
			num = num * 10 + s[i] - '0';
			i++;
		}
		if (num != -1)
		{
			i--;
			sum += num;
		}
		i++;
	}
	return sum;
}

double tinhGiatri(Node* head, double x)
{
	float re = 0;
	for (Node* p = head; p; p = p->pnext)
	{
		float ex = 1;
		int th = p->th;

		int hs = p->num;

		for (int i = 0; i < th; i++)
		{
			ex *= x;
		}
		re += hs * ex;
	}
	return re;
}

Node* getNode(int k, int t)
{
	return new Node{ k,t,nullptr };
}

void createList(Node*& head)
{
	head = getNode(2, 4);
	Node* p2 = nullptr, * p3 = nullptr;

	p2 = getNode(2, 3);
	head->pnext = p2;

	p3 = getNode(4, 2);
	p2->pnext = p3;

}

void deList(Node* head)
{
	Node* p = head;
	while (head)
	{
		head = head->pnext;
		delete p;
		p = nullptr;
	}
}


void inNhiPhan(int n)
{
	if (n == 1)
		printf("%d", n);
	else
	{
		inNhiPhan(n / 2);
		printf("%d", n % 2);
	}
}

void createBinFile()
{
	int32_t m = 5;
	FILE* f_out = fopen("dagiac.bin", "wb");
	fwrite(&m, sizeof(m), 1, f_out);
	Point a[3] = { {2,1}, {3,4} ,{5,6} };
	Point b[3] = { {4,6}, {7,4} ,{8,6} };
	Point c[3] = { {7,2}, {3,5} ,{4,3} };
	Point d[3] = { {3,2}, {3,4} ,{5,6} };
	Point e[3] = { {4,3}, {3,5} ,{5,7} };
	int n = 3;
	fwrite(&n, sizeof(n), 1, f_out);
	fwrite(a, sizeof(struct Point), 3, f_out);
	fwrite(&n, sizeof(n), 1, f_out);
	fwrite(b, sizeof(struct Point), 3, f_out);
	fwrite(&n, sizeof(n), 1, f_out);
	fwrite(c, sizeof(struct Point), 3, f_out);
	fwrite(&n, sizeof(n), 1, f_out);
	fwrite(d, sizeof(struct Point), 3, f_out);
	fwrite(&n, sizeof(n), 1, f_out);
	fwrite(e, sizeof(struct Point), 3, f_out);
	fclose(f_out);
}

void readData(char* path, Point** store)
{
	FILE* f_in = fopen(path, "rb");
	if (f_in == NULL)
	{
		printf("can't open!\n");
		return;
	}
	int m;
	fread(&m, sizeof(int), 1, f_in);
	store = new Point * [m];

	for (int i = 0; i < m; i++)
	{
		int n;
		fread(&n, sizeof(n), 1, f_in);
		store[i] = new Point[n];
		fread(store[i], sizeof(Point), n, f_in);
	}

	fclose(f_in);
}

int main()
{
	char path[] = "dagiac.bin";
	createBinFile();
	Point** store;
	readData(path, store);
}