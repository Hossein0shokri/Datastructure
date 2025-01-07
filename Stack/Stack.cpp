#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    void Push(int item) {
        if (top == MAX_SIZE - 1) {
            cout << "Error: Stack is full" << endl;
            return;
        }
        arr[++top] = item;
    }

    int Pop() {
        if (IsEmpty()) {
            cout << "Error: Stack is empty" << endl;
            return -1;
        }
        return arr[top--];
    }

    int Peek() {
        if (IsEmpty()) {
            cout << "Error: Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }

    bool IsEmpty() {
        return (top == -1);
    }
};

int main() {
    Stack stack;

    stack.Push(10);
    stack.Push(20);
    stack.Push(30);

    cout << "Top element: " << stack.Peek() << endl; // 30

    cout << "Popped: " << stack.Pop() << endl; // 30
    cout << "Popped: " << stack.Pop() << endl; // 20

    stack.Push(40);
    cout << "Popped: " << stack.Pop() << endl; // 40

    return 0;
}
