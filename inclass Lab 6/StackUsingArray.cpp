#include <iostream>

using namespace std;

class StackUsingArray {
private:
    int* data;
    int top;
    int size;

public:
    StackUsingArray(int size) {
        this->size = size;
        data = new int[size];
        top = -1;
    }

    void push(int value) {
        if (top == size - 1) {
            cout << "Stack Overflow";
        }
        top++;
        data[top] = value;
    }

    int pop() {
        if (top == -1) {
            cout << "Stack Underflow";
        }
        int value = data[top];
        top--;
        return value;
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
        }
        else {
            cout << "Stack elements: ";
            for (int i = 0; i <= top; i++) {
                cout << data[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    StackUsingArray s(10);

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

    return 0;
}
