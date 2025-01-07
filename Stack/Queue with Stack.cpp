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

    bool IsEmpty() {
        return (top == -1);
    }
};

class QueueUsingStacks {
private:
    Stack stack1, stack2;

public:
    void Enqueue(int item) {
        stack1.Push(item);
    }

    int Dequeue() {
        if (stack2.IsEmpty()) {
            while (!stack1.IsEmpty()) {
                stack2.Push(stack1.Pop());
            }
        }

        if (stack2.IsEmpty()) {
            cout << "Error: Queue is empty" << endl;
            return -1;
        }

        return stack2.Pop();
    }

    bool IsEmpty() {
        return stack1.IsEmpty() && stack2.IsEmpty();
    }
};

int main() {
    QueueUsingStacks queue;

    queue.Enqueue(10);
    queue.Enqueue(20);
    queue.Enqueue(30);

    cout << "Dequeued: " << queue.Dequeue() << endl; // 10
    cout << "Dequeued: " << queue.Dequeue() << endl; // 20

    queue.Enqueue(40);
    queue.Enqueue(50);

    while (!queue.IsEmpty()) {
        cout << "Dequeued: " << queue.Dequeue() << endl;
    }

    return 0;
}
