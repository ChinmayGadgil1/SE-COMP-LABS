#include <iostream>
using namespace std;

int main()
{
	int r,c;
	cout<<"Enter the number of rows and columns: ";
	cin>>r>>c;
	if (r!=c)
	{
		cout<<"True diagonals exist for square matrix only"<<endl;
		cout<<"Rerun the program";
		exit(1);
	}
	
	int mat[r][c];

	cout<<"Enter matrix:"<<endl;
	for (int i = 0; i < r; i++)
	{	
		cout<<"Row "<<i+1<<" :";
		for (int j = 0; j < c; j++)
		{
			cin>>mat[i][j];
		}
		
	}

		cout<<"\nYour matrix:"<<endl;
	for (int i = 0; i < r; i++)
	{	
		for (int j = 0; j < c; j++)
		{
			cout<<mat[i][j]<<"  ";
		}
		cout<<endl;
	}
	

	int temp;
	for (int i = 0; i < r; i++)
	{
		temp = mat[i][i];
		mat[i][i] = mat[i][r-1 - i];
		mat[i][r-1 - i] = temp;
	}

		cout<<"\nMatrix after swapping diagonals:"<<endl;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << mat[i][j]<<"  ";
		}
		cout << endl;
	}

	return 0;
}
