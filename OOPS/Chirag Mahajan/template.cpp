#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T val) : data(val), next(nullptr) {}

    Node* operator+(T val) {
        Node* newNode = new Node(val);
        newNode->next = this;
        return newNode;
    }

    Node* operator-(T val) {
        Node* temp = this;
        Node* prev = nullptr;

        while (temp != nullptr && temp->data != val) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) return this;

        if (prev == nullptr) {
            Node* nextNode = temp->next;
            delete temp;
            return nextNode;
        } else {
            prev->next = temp->next;
            delete temp;
            return this;
        }
    }

    Node* operator+(Node* other) {
        if (this == nullptr) return other;
        if (other == nullptr) return this;

        Node* temp = this;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = other;
        return this;
    }

    void display() {
        Node* temp = this;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Node<int>* node1 = new Node<int>(1);
    node1 = *node1 + 2;
    node1 = *node1 + 3;
    node1->display();

    node1 = *node1 - 2;
    node1->display();

    Node<int>* node2 = new Node<int>(4);
    node2 = *node2 + 5;
    node2->display();

    Node<int>* mergedNode = *node1 + node2;
    mergedNode->display();

    return 0;
}