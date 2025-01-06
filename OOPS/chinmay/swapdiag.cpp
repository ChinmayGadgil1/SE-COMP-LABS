#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
	int r, c;
	try
	{
		cout << "Enter the number of rows and columns: ";
		cin >> r >> c;
		if (r != c)
		{
			throw runtime_error("For diagonal to exist number of row and columns must be equal");
		}
		int mat[r][c];

		cout << "Enter matrix:" << endl;
		for (int i = 0; i < r; i++)
		{
			cout << "Row " << i + 1 << " :";
			for (int j = 0; j < c; j++)
			{
				cin >> mat[i][j];
			}
		}

		cout << "\nYour matrix:" << endl;
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cout << mat[i][j] << "  ";
			}
			cout << endl;
		}

		int temp;
		for (int i = 0; i < r; i++)
		{
			temp = mat[i][i];
			mat[i][i] = mat[i][r - 1 - i];
			mat[i][r - 1 - i] = temp;
		}

		cout << "\nMatrix after swapping diagonals:" << endl;
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cout << mat[i][j] << "  ";
			}
			cout << endl;
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
