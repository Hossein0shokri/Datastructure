#include <iostream>
using namespace std;

struct node {
    int data;
    struct node* next;
} *top = NULL;

void push(int value) {
    struct node* newNode = new node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

void pop() {
    if (top == NULL) {
        cout << "Stack is empty." << endl;
        return;
    }
    struct node* temp = top;
    top = top->next;
    delete temp;
}

void display() {
    struct node* temp = top;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);

    cout << "Stack: ";
    display();

    pop();
    cout << "Stack after pop: ";
    display();

    return 0;
}