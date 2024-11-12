#include <iostream>
using namespace std;

template <class T>
class Vector
{
private:
    T *vec;
    int size;

public:
    Vector(int size)
    {
        this->size = size;
        vec = new T[size];
    }
    void createVector(const T *elements)
    {
        for (int i = 0; i < size; i++)
        {
            vec[i] = elements[i];
        }
    }
    void modifyElement()
    {
        int index;
        T value;
        cout << "Enter index and new value: ";
        cin >> index >> value;
        if (index < size)
        {
            vec[index] = value;
        }
        else
        {
            cerr << "Index out of bounds" << endl;
        }
    }
    void displayVector() const
    {
        for (int i = 0; i < size; i++)
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    void changeSize(int newSize)
    {
        T *newVec = new T[newSize];
        for (int i = 0; i < (newSize < size ? newSize : size); i++)
        {
            newVec[i] = vec[i];
        }
        if (newSize > size)
        {
            cout << "Enter " << newSize - size << " elements:\n";
            for (int i = size; i < newSize; i++)
            {
                cin >> newVec[i];
            }
        }
        delete[] vec;
        vec = newVec;
        size = newSize;
    }
    ~Vector()
    {
        delete[] vec;
    }
};

int main()
{

    int choice, size, index;
    cout << "Select the data type for the vector:\n";
    cout << "1. int\n";
    cout << "2. float\n";
    cout << "3. double\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        cout << "Enter the size of the vector: ";
        cin >> size;
        Vector<int> vec(size);
        int *elements = new int[size];
        cout << "Enter the elements of the vector: ";
        for (int i = 0; i < size; i++)
        {
            cin >> elements[i];
        }
        vec.createVector(elements);
        delete[] elements;

        do
        {
            cout << "\nMenu:\n";
            cout << "1. Display Vector\n";
            cout << "2. Modify Element\n";
            cout << "3. Change Size\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                vec.displayVector();
                break;
            case 2:
                vec.modifyElement();
                break;
            case 3:
                cout << "Enter new size: ";
                cin >> size;
                vec.changeSize(size);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
            }
        } while (choice != 4);
        break;
    }
    case 2:
    {
        cout << "Enter the size of the vector: ";
        cin >> size;
        Vector<float> vec(size);
        float *elements = new float[size];
        cout << "Enter the elements of the vector: ";
        for (int i = 0; i < size; i++)
        {
            cin >> elements[i];
        }
        vec.createVector(elements);
        delete[] elements;

        do
        {
            cout << "\nMenu:\n";
            cout << "1. Display Vector\n";
            cout << "2. Modify Element\n";
            cout << "3. Change Size\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                vec.displayVector();
                break;
            case 2:
                vec.modifyElement();
                break;
            case 3:
                cout << "Enter new size: ";
                cin >> size;
                vec.changeSize(size);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
            }
        } while (choice != 4);
        break;
    }
    case 3:
    {
        cout << "Enter the size of the vector: ";
        cin >> size;
        Vector<double> vec(size);
        double *elements = new double[size];
        cout << "Enter the elements of the vector: ";
        for (int i = 0; i < size; i++)
        {
            cin >> elements[i];
        }
        vec.createVector(elements);
        delete[] elements;

        do
        {
            cout << "\nMenu:\n";
            cout << "1. Display Vector\n";
            cout << "2. Modify Element\n";
            cout << "3. Change Size\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                vec.displayVector();
                break;
            case 2:
                vec.modifyElement();
                break;
            case 3:
                cout << "Enter new size: ";
                cin >> size;
                vec.changeSize(size);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
            }
        } while (choice != 4);
        break;
    }
    default:
        cout << "Invalid data type choice. Exiting...\n";
    }
    return 0;
}