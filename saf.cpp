#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Queue {
private:
    int arr[MAX_SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void Enqueue(int element) {
        if (rear == MAX_SIZE - 1) {
            cout << "Error: Queue is full" << endl;
            return;
        }
        if (front == -1) {
            front = 0;
        }
        rear++;
        arr[rear] = element;
    }

    int Dequeue() {
        if (front == -1 || front > rear) {
            cout << "Error: Queue is empty" << endl;
            return -1;
        }
        int value = arr[front];
        front++;
        return value;
    }

    int Peek() {
        if (front == -1 || front > rear) {
            cout << "Error: Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    bool IsEmpty() {
        return (front == -1 || front > rear);
    }

    bool IsFull() {
        return (rear == MAX_SIZE - 1);
    }
};

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
        if ((rear + 1) % MAX_SIZE == front) {
            cout << "Error: Queue is full" << endl;
            return;
        }
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = element;
    }

    int Dequeue() {
        if (front == -1) {
            cout << "Error: Queue is empty" << endl;
            return -1;
        }
        int value = arr[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
        return value;
    }

    int Peek() {
        if (front == -1) {
            cout << "Error: Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    bool IsEmpty() {
        return (front == -1);
    }

    bool IsFull() {
        return ((rear + 1) % MAX_SIZE == front);
    }
};

int main() {
    int choice;
    cout << "Select Queue Type:\n1. Normal Queue\n2. Circular Queue\nEnter choice: ";
    cin >> choice;

    if (choice == 1) {
        Queue q;
        q.Enqueue(10);
        q.Enqueue(20);
        q.Enqueue(30);
        cout << "Front element: " << q.Peek() << endl;
        cout << "Dequeued element: " << q.Dequeue() << endl;
        cout << "Front element: " << q.Peek() << endl;
    } else if (choice == 2) {
        CircularQueue cq;
        cq.Enqueue(10);
        cq.Enqueue(20);
        cq.Enqueue(30);
        cout << "Front element: " << cq.Peek() << endl;
        cout << "Dequeued element: " << cq.Dequeue() << endl;
        cout << "Front element: " << cq.Peek() << endl;
        cq.Enqueue(40);
        cq.Enqueue(50);

        while (!cq.IsEmpty()) {
            cout << "Dequeued: " << cq.Dequeue() << endl;
        }
    } else {
        cout << "Invalid choice" << endl;
    }

    return 0;
}
