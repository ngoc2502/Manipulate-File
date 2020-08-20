# include<iostream>
# include<math.h>
using namespace std;
int ptbachai(int a, int b, int c,float &x1, float &x2, int &deta)
{
	if (a == 0) x1 = -c / b;
	else
	{
		deta = b * b - 4 * a * c;
		if (deta == 0) x1 = -b / 2 * a;
		else if (deta>0)
		{
			x1 = -b - sqrt(deta) / 2 * a;
			x2 = -b + sqrt(deta) / 2 * a;
		}
	}
	return 0;
}