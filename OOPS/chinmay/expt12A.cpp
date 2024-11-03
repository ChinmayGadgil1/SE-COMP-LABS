#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> numbers;
    int choice, n, input;

        cout << "\nMenu:\n";
        cout << "1. Add elements to vector\n";
        cout << "2. Display vector elements\n";
        cout << "3. Modify element\n";
        cout << "4. Push back element\n";
        cout << "5. Pop back element\n";
        cout << "6. Display vector size\n";
        cout << "7. Exit";
    do
    {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the number of elements: ";
            cin >> n;
            cout<<"Enter elements:";
            for (int i = 0; i < n; ++i)
            {
                // cout << "Enter element " << i + 1 << ": ";
                cin >> input;
                numbers.push_back(input);
            }
            break;

        case 2:
            cout << "Vector elements: ";
            for (int num : numbers)
            {
                cout << num << " ";
            }
            cout << endl;
            break;

        case 3:
            if (!numbers.empty())
            {
                int index, newValue;
                cout << "Enter the index of the element to modify: ";
                cin >> index;
                if (index >= 0 && index < numbers.size())
                {
                    cout << "Enter the new value: ";
                    cin >> newValue;
                    numbers[index] = newValue;
                    cout << "Modified element at index " << index << ": " << numbers[index] << endl;
                }
                else
                {
                    cout << "Invalid index." << endl;
                }
            }
            else
            {
                cout << "Vector is empty, cannot modify elements." << endl;
            }
            break;
        case 4:
            cout << "Enter the element to push back: ";
            cin >> input;
            numbers.push_back(input);
            cout << "Vector after push_back: ";
            for (int num : numbers)
            {
                cout << num << " ";
            }
            cout << endl;
            break;
        case 5:
            if (!numbers.empty())
            {
                numbers.pop_back();
                cout << "Vector after pop_back: ";
                for (int num : numbers)
                {
                    cout << num << " ";
                }
                cout << endl;
            }
            else
            {
                cout << "Vector is empty, cannot pop back." << endl;
            }
            break;

        case 6:
            cout << "Vector size: " << numbers.size() << endl;
            break;

        case 7:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}