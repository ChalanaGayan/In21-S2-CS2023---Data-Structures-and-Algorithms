#include <iostream>
#include <chrono>  
using namespace std;
using namespace std::chrono;

class Node {
public:
    int data;
    Node* next;
};

class StackUsingLinkedList {
private:
    Node* top;

public:
    StackUsingLinkedList() {
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
            cout << "Stack Underflow" << endl;
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

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Stack: ";
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    auto start = high_resolution_clock::now();  // start the timer

    StackUsingLinkedList s;

    s.push(8);
    s.push(10);
    s.push(5);
    s.push(11);
    s.push(15);
    s.push(23);
    s.push(6);
    s.push(18);
    s.push(20);
    s.push(17);

    cout << "Start stack: ";
    s.display();

    for (int i = 0; i < 5; i++) {
        s.pop();
    }

    cout << "After popping 5 times: ";
    s.display();

    s.push(4);
    s.push(30);
    s.push(3);
    s.push(1);

    cout << "After pushing itrems ";
    s.display();

    auto stop = high_resolution_clock::now();  // stop the timer
    auto duration = duration_cast<microseconds>(stop - start);  // calculate the duration

    cout << "Execution time: " << duration.count() << " microseconds." << endl;

    return 0;
}
