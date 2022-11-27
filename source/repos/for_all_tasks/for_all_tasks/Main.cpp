#include <iostream>

using namespace std;

int main()
{
	int a1, b1, c1; //1st box
	cin >> a1 >> b1 >> c1;

	int p1, p2, p3; // периметр
	p1 = 2 * a1 + 2 * c1;
	p2 = 2 * a1 + 2 * b1;
	p3 = 2 * b1 + 2 * c1;

	int s1 = a1 * b1 * c1;//square

	int a2, b2, c2;//2nd box
	cin >> a2 >> b2 >> c2;

	int p11, p12, p13;//перисетр 2
	p11 = 2 * a2 + 2 * c2;
	p12 = 2 * a2 + 2 * b2;
	p13 = 2 * c2 + 2 * b2;

	int s2 = a2 * b2 * c2;//square 2

	if (s1 == s2)
	{
		cout << "Boxes are equal";
	}
	else if (s1 < s2 && p1 < )
	{
		cout << "The first box is smaller than the second one";
	}
	else if(s1 > s2)
	{
		cout << "The first box is larger than the second one";
	}
	else
	{
		cout << "Boxes are incomparable";
	}
}