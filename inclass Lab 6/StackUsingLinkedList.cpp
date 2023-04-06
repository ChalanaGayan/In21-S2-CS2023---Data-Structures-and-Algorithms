#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class StackUsingLinkedList {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (top == nullptr) {
            cout << "Stack Underflow" << endl;;
        }

        int value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;

        return value;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {
     
    return 0;
}
