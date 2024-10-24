#include <iostream>
#include <stdexcept>
using namespace std;

class Queue {
private:
    int* arr;
    int front;
    int rear;
    int capacity;
    int count;

public:
    Queue(int size = 10);
    ~Queue();

    void enqueue(int x);
    int dequeue();
    int peek();
    int size();
    bool isEmpty();
    bool isFull();
};

Queue::Queue(int size) {
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

Queue::~Queue() {
    delete[] arr;
}

void Queue::enqueue(int x) {
    if (isFull()) {
        throw overflow_error("Queue Overflow: Cannot enqueue to a full queue.");
    }

    rear = (rear + 1) % capacity;
    arr[rear] = x;
    count++;
}

int Queue::dequeue() {
    if (isEmpty()) {
        throw underflow_error("Queue Underflow: Cannot dequeue from an empty queue.");
    }

    int x = arr[front];
    front = (front + 1) % capacity;
    count--;
    return x;
}

int Queue::peek() {
    if (isEmpty()) {
        throw underflow_error("Queue Underflow: Cannot peek from an empty queue.");
    }
    return arr[front];
}

int Queue::size() {
    return count;
}

bool Queue::isEmpty() {
    return (count == 0);
}

bool Queue::isFull() {
    return (count == capacity);
}

int main() {
    Queue q(5);
    int choice, value;

    while (true) {
        cout << "\nQueue Menu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Size\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        try {
            switch (choice) {
                case 1:
                    cout << "Enter value to enqueue: ";
                    cin >> value;
                    q.enqueue(value);
                    cout << "Enqueued " << value << endl;
                    break;
                case 2:
                    value = q.dequeue();
                    cout << "Dequeued " << value << endl;
                    break;
                case 3:
                    value = q.peek();
                    cout << "Front element is " << value << endl;
                    break;
                case 4:
                    cout << "Queue size is " << q.size() << endl;
                    break;
                case 5:
                    cout << (q.isEmpty() ? "Queue is empty" : "Queue is not empty") << endl;
                    break;
                case 6:
                    cout << (q.isFull() ? "Queue is full" : "Queue is not full") << endl;
                    break;
                case 7:
                    exit(0);
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    return 0;
}