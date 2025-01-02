#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
    try
    {

        int age;
        cout << "Enter your age: ";
        cin >> age;

        if (age < 0)
        {
            throw invalid_argument("Age cannot be negative.");
        }
        else if (age > 150)
        {
            throw out_of_range("Age seems unrealistic.");
        }

        cout << "Your age is: " << age << endl;
    }
    catch (const invalid_argument &e)
    {
        cerr << "Invalid argument: " << e.what() << endl;
    }
    catch (const out_of_range &e)
    {
        cerr << "Out of range error: " << e.what() << endl;
    }
    catch (...)
    {
        cerr << "An unexpected error occurred." << endl;
    }
    return 0;
}