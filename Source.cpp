# include<iostream>
# include<fstream>
using namespace std;
int ptbachai(int a, int b, int c, float& x1, float& x2, int& deta);
int main()
{
	int a, b, c,d;
	float x1, x2;
	//docfile
	fstream f;
	f.open("input.txt");
	f >> a >> b >> c;
	ptbachai(a, b, c, x1, x2, d);
	if (d == 0) cout << x1;
	else if (d < 0) cout << "vo nghiem! ";
	else cout << x1 << "  " << x2;
	f.close();

	cout << "\n=====================" << endl;
	// ghi file
	cout << "xem kq trong file output.txt\n";
	fstream f1;
	f1.open("output.txt");
	if (d == 0) f1 << x1;
	else if (d < 0) f1 << "vo nghiem! ";
	else f1 << x1 << "  " << x2;
	f1.close();
	return 0;

}