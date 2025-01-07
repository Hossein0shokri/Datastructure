#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class CircularQueue {
private:
    int arr[MAX_SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    void Enqueue(int element) {
        if (IsFull()) {
            cout << "Error: Queue is full" << endl;
            return;
        }
        if (front == -1) {
            front = 0;
        }
        if (rear == MAX_SIZE - 1) {
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = element;
    }

    int Dequeue() {
        if (IsEmpty()) {
            cout << "Error: Queue is empty" << endl;
            return -1;
        }
        int item = arr[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (front == MAX_SIZE - 1) {
            front = 0;
        } else {
            front++;
        }
        return item;
    }

    int Peek() {
        if (IsEmpty()) {
            cout << "Error: Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    bool IsEmpty() {
        return (front == -1);
    }

    bool IsFull() {
        return ((rear == MAX_SIZE - 1 && front == 0) || (rear + 1 == front));
    }

    void ReverseQueue() {
        if (IsEmpty()) {
            return;
        }
        int temp = Dequeue();
        ReverseQueue();
        Enqueue(temp);
    }
};

int main() {
    CircularQueue cq;

    cq.Enqueue(10);
    cq.Enqueue(20);
    cq.Enqueue(30);

    cout << "Original Queue:" << endl;
    while (!cq.IsEmpty()) {
        cout << cq.Dequeue() << " ";
    }
    cout << endl;

    cq.Enqueue(10);
    cq.Enqueue(20);
    cq.Enqueue(30);

    cq.ReverseQueue();

    cout << "Reversed Queue:" << endl;
    while (!cq.IsEmpty()) {
        cout << cq.Dequeue() << " ";
    }
    cout << endl;

    return 0;
}
