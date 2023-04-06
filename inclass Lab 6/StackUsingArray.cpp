#include <iostream>

using namespace std;

class StackUsingArray {

private:
    int* data;
    int top;
    int size;

public:
    Stack(int size) {
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
            cout << "Stack Under flow";
        }
        int value = data[top];
        top--;
        return value;
    }
};


int main()
{
    
}



