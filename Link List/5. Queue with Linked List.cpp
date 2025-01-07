#include <iostream>
using namespace std;

struct node {
    int data;
    struct node* next;
} *front = NULL, *rear = NULL;

void enqueue(int value) {
    struct node* newNode = new node;
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() {
    if (front == NULL) {
        cout << "Queue is empty." << endl;
        return;
    }
    struct node* temp = front;
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    delete temp;
}

void display() {
    struct node* temp = front;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    cout << "Queue: ";
    display();

    dequeue();
    cout << "Queue after dequeue: ";
    display();

    return 0;
}
