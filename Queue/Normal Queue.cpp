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

    void Enqueue(int num) {
        if (rear == MAX_SIZE - 1) {
            cout << "Error: Queue is full" << endl;
            return;
        }
        if (front == -1) {
            front = 0;
        }
        rear++;
        arr[rear] = num;
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
    Queue q;

    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);

    cout << "Original Queue Front: " << q.Peek() << endl;
    
    q.ReverseQueue();

    cout << "Queue After Reversal: " << q.Peek()<< endl;
    while (!q.IsEmpty()) {
        cout << "Dequeued: " << q.Dequeue() << endl;
    }

    return 0;
}