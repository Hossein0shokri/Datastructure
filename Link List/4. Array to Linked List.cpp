#include <iostream>
using namespace std;

struct node {
    int data;
    struct node* next;
} *start = NULL;

void append(int value) {
    struct node* newNode = new node;
    newNode->data = value;
    newNode->next = NULL;

    if (start == NULL) {
        start = newNode;
    } else {
        struct node* temp = start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void display() {
    struct node* temp = start;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++) {
        append(arr[i]);
    }

    cout << "Linked list: ";
    display();

    return 0;
}
