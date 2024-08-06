#include <iostream>

using namespace std;

class stack
{
    int size;
    int top;
    int *arr;

public:
    stack()
    {
        cout << "Enter size of stack: ";
        cin >> size;
        arr = new int[size]{0};
        top = -1;
    }
    ~stack()
    {
        cout<<"\nDestructor Called\n";
        delete arr;
    }
    bool isEmpty()
    {
        return top == -1;
    }
    bool isFull()
    {
        return top == size - 1;
    }
    void push(int);
    int pop();

    void populate();
    void display();
    int peek();
};

void stack::push(int data)
{
    if (isFull())
    {
        cout << "\nStack Overflow\n";
        return;
    }
    arr[++top] = data;
}

int stack::pop()
{
    if (isEmpty())
    {
        cout << "\nStack Underflow\n";
        return INT32_MIN;
    }
    return arr[top--];
}

int stack::peek()
{
    if (isEmpty())
    {
        cout << "\nStack Empty\n";
        return INT32_MIN;
    }
    return arr[top];
}

void stack::populate()
{
    int choice,data;
    while (1)
    {
        cout << endl
             << "What would you like to do?\n"
             << "1.Push\n2.Pop\n3.Peek\n4.Exit\n"
                "Your choice=> \n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter data to push: ";
            data;
            cin >> data;
            push(data);
            display();
            break;
        case 2:
            data = pop();
            if (data != INT32_MIN)
            {
                cout << "Popped data: " << data<<"\n";
            }
            display();
            break;
        case 3:
            data = peek();
            if (data != INT32_MIN)
            {
                cout << "data at top: " << data<<"\n";
            }
            display();
            break;
        case 4:
            cout<<"\nexiting...\n";
            return;
        }
    }
    return;
}

void stack::display(){
    if(isEmpty()){
        cout<<"\nStack Empty\n";
    }
    for(int i=top;i>=0;i--){
        cout<<arr[i]<<"  ";
    }
    cout<<"\n";
}

int main()
{
    stack s;
    s.populate();

    return 0;
}