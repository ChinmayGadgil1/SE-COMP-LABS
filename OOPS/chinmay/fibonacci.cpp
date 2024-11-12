#include <iostream>
using namespace std;

int main()
{

	int n;
	cout << "Enter Number of rows: ";
	cin >> n;
	cout << endl;
	int a, b, c;
	for (int i = 0; i < n; i++)
	{

		a = b = 1;

		for (int j = 0; j <= i; j++)
		{
			cout << a << " ";
			c = a + b;
			a = b;
			b = c;
		}
	}
}
