#include <iostream>
using namespace std;

class Deque
{
private:
    string *arr;
    int front;
    int rear;
    int size;
 
public:
    Deque()
    {
        cout << "Enter size: ";
        cin >> size;
        arr = new string[size]{""};
        front = -1;
        rear = size;
    }
    ~Deque()
    {
        delete[] arr;
    }
    bool isFull()
    {
        return  front >= rear || rear==0 || front == size - 1;
    }

    bool isFrontEmpty()
    {
        return front == -1;
    }

    bool isRearEmpty()
    {
        return rear == size;
    }

    void push_front(string);
    void push_back(string);
    string pop_front();
    string pop_back();
    void ForEach();
    void FirstThat(string);
    void fill();
    void getLeft();
    void getRight();
};

void Deque::push_front(string a)
{
    if (isFull())
    {
        cout << "\nDeque Overflow\n";
        return;
    }

    front++;
    arr[front] = a;
}

void Deque::push_back(string a)
{
    if (isFull())
    {
        cout << "\nDeque Overflow\n";
        return;
    }
    rear--;
    arr[rear] = a;
}

string Deque::pop_front()
{
    if (isFrontEmpty())
    {
        cout << "\nDeque Underflow\n";
        return "NOTFOUND";
    }

    string pop = arr[front];
    front--;
    return pop;
}
string Deque::pop_back()
{
    if (isRearEmpty())
    {
        cout << "\nDeque Underflow\n";
        return "NOTFOUND";
    }

    string pop = arr[rear];
    rear++;
    return pop;
}

void Deque::ForEach()
{
    if (isFrontEmpty())
    {
        cout << "\nFront Empty\n";
    }
    else
    {
        cout << "\nArray from Front:\n";
        for (int i = 0; i <= front; i++)
        {
            cout << arr[i] << "   ";
        }
        cout << "\n";
    }
    if (isRearEmpty())
    {
        cout << "\nRear Empty\n";
    }
    else
    {
        cout << "\nArray from Rear:\n";
        for (int i = size - 1; i >= rear; i--)
        {
            cout << arr[i] << "   ";
        }
        cout << "\n";
    }
}

void Deque::FirstThat(string s)
{
    if (!isFrontEmpty())
    {
        for (int i = 0; i <= front; i++)
        {
            if (arr[i] == s)
            {
                cout << "At index=" << i << " found " << arr[i] << "\n";
            }
        }
    }
    if (!isRearEmpty())
    {
        for (int i = size - 1; i >= rear; i--)
        {
            if (arr[i] == s)
            {
                cout << "At index=" << i << " found " << arr[i] << "\n";
            }
        }
    }
}

void Deque::getLeft()
{
    if (isFrontEmpty())
    {
        cout << "\nDeque Empty from Front\n";
        return;
    }
    cout << "\n";
    while (!isFrontEmpty())
    {
        cout << pop_front() << "  ";
    }
    cout << "\n";
}
void Deque::getRight()
{
    if (isRearEmpty())
    {
        cout << "\nDeque Empty from Rear \n";
        return;
    }
    cout << "\n";
    while (!isRearEmpty())
    {
        cout << pop_back() << "  ";
    }
    cout << "\n";
}

void Deque::fill()
{
    int n;
    cout << "\nHow many elements would you like to push to front?\n";
    cin >> n;
    cout << "\nEnter " << n << " strings\n";
    for (int i = 0; i < n; i++)
    {
        string push;
        cin >> push;
        push_front(push);
    }

    cout << "\nHow many elements would you like to push to back?\n";
    cin >> n;
    cout << "\nEnter " << n << " strings\n";
    for (int i = 0; i < n; i++)
    {
        string push;
        cin >> push;
        push_back(push);
    }
}

int main()
{

    Deque q;
    int choice;
    string s;
    
    while (true)
    {
        cout << "\n1.Fill\n2.Display\n3.getLeft\n4.getRight\n5.Search\n6.Exit\n";
        cout << "Enter your choice=> ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            q.fill();
            break;
        case 2:
            q.ForEach();
            break;
        case 3:
            q.getLeft();
            break;
        case 4:
            q.getRight();
            break;
        case 5:
            cout<<"\nEnter string to search: ";
            cin>>s;
            q.FirstThat(s);
            break;
        case 6:
            exit(0);
        default:
            break;
        }
    }

    return 0;
}