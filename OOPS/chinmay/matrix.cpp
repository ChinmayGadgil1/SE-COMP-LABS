#include <iostream>
using namespace std;

class Matrix
{
private:
    int **data;
    int rows;
    int cols;

    void allocateMemory()
    {
        data = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            data[i] = new int[cols];
        }
    }

    void deallocateMemory()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] data[i];
        }
        delete[] data;
    }

public:
    Matrix(int m = 0, int n = 0)
    {
        rows = m;
        cols = n;
        if (rows > 0 && cols > 0)
        {
            allocateMemory();
        }
        else
        {
            data = NULL;
        }
    }

    Matrix(const Matrix &other)
    {
        rows = other.rows;
        cols = other.cols;
        allocateMemory();
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                data[i][j] = other.data[i][j];
            }
        }
    }

    ~Matrix()
    {
        if (data != NULL)
        {
            deallocateMemory();
        }
    }

    Matrix &operator=(const Matrix &other)
    {
        if (this == &other)
        {
            return *this;
        }

        if (data != NULL)
        {
            deallocateMemory();
        }

        rows = other.rows;
        cols = other.cols;
        allocateMemory();
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                data[i][j] = other.data[i][j];
            }
        }

        return *this;
    }

    void inputMatrix()
    {
        cout << "Enter the elements of the matrix:" << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cin >> data[i][j];
            }
        }
    }

    Matrix operator+(const Matrix &other) const
    {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator-(const Matrix &other) const
    {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix &other) const
    {
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < other.cols; j++)
            {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; k++)
                {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    void displayMatrix() const
    {
        cout << "Matrix:" << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
    ~Matrix(){
        deallocateMemory();
    }
};

int main()
{
    int m, n, j, k;
    cout << "Enter the number of rows and columns for the matrices: ";
    cin >> m >> n;
    Matrix matrix1(m, n);
    Matrix matrix2(m, n);
    Matrix matrix3;

    cout << "Enter elements for matrix 1:" << endl;
    matrix1.inputMatrix();

    cout << "Enter elements for matrix 2:" << endl;
    matrix2.inputMatrix();

    int choice;
    while (true)
    {
        cout << "Menu:" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            matrix3 = matrix1 + matrix2;
            cout << "Result of addition:" << endl;
            matrix3.displayMatrix();
            break;
        case 2:
            matrix3 = matrix1 - matrix2;
            cout << "Result of subtraction:" << endl;
            matrix3.displayMatrix();
            break;
        case 3:
            matrix3 = matrix1 * matrix2;
            cout << "Result of multiplication:" << endl;
            matrix3.displayMatrix();
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}