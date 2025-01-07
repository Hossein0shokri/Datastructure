#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
} *start = NULL;

node *create_node(int val)
{
    struct node *n;
    n = new (struct node);
    
        n->data = val;
        n->next = NULL;
        return n;
    
}

void InsertAtBegin(int data)
{
    struct node *n = create_node(data);
    if (n == NULL)
        return;

    if (start == NULL)
    {
        start = n;
    }
    else
    {
        n->next = start;
        start = n;
    }
}

void InsertAtEnd(int data)
{
    struct node *n = create_node(data);
    if (n == NULL)
        return;

    if (start == NULL)
    {
        start = n;
        return;
    }

    struct node *s = start;
    while (s->next != NULL)
    {
        s = s->next;
    }
    s->next = n;
}

void InsertAtIndex(int data, int index)
{
    struct node *n = create_node(data);
    if (n == NULL)
        return;

    if (index == 1)
    {
        n->next = start;
        start = n;
        return;
    }

    struct node *s = start, *p = NULL;
    int i = 1;

    while (s != NULL && i < index)
    {
        p = s;
        s = s->next;
        i++;
    }

    if (i == index)
    {
        p->next = n;
        n->next = s;
    }
    else
    {
        cout << "Position out of range" << endl;
        delete n;
    }
}

void display()
{
    struct node *t = start;
    if (t == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    cout << "Elements: ";
    while (t != NULL)
    {
        cout << t->data << "->";
        t = t->next;
    }
    cout << "NULL" << endl;
}

void UpdateNode(int data, int index)
{
    struct node *current = start;
    int position = 1;

    while (current != NULL && position < index)
    {
        current = current->next;
        position++;
    }

    if (current == NULL)
    {
        cout << "Position out of range." << endl;
        return;
    }

    current->data = data;
}

int RemoveNodeAtIndex(int index)
{
    if (start == NULL)
    {
        cout << "The list is empty." << endl;
        return -1;
    }

    struct node *s = start, *p = NULL;
    int position = 1;

    if (index == 1)
    {
        int data = start->data;
        start = start->next;
        delete s;
        return data;
    }

    while (s != NULL && position < index)
    {
        p = s;
        s = s->next;
        position++;
    }

    if (s == NULL)
    {
        cout << "Position out of range." << endl;
        return -1;
    }

    p->next = s->next;
    int data = s->data;
    delete s;
    return data;
}

int RemoveNodeAtBegin()
{
    if (start == NULL)
    {
        cout << "The list is empty." << endl;
        return -1;
    }

    struct node *temp = start;
    int data = temp->data;
    start = start->next;
    delete temp;
    return data;
}

int RemoveNodeAtEnd()
{
    if (start == NULL)
    {
        cout << "The list is empty." << endl;
        return -1;
    }

    struct node *current = start, *previous = NULL;

    while (current->next != NULL)
    {
        previous = current;
        current = current->next;
    }

    if (previous == NULL)
    {
        int data = start->data;
        delete start;
        start = NULL;
        return data;
    }

    int data = current->data;
    previous->next = NULL;
    delete current;
    return data;
}

int SizeOfList()
{
    struct node *current = start;
    int size = 0;
    while (current != NULL)
    {
        size++;
        current = current->next;
    }
    return size;
}

void Concatenate(struct node *otherList)
{
    if (otherList == NULL)
    {
        cout << "Other list is empty." << endl;
        return;
    }

    if (start == NULL)
    {
        start = otherList;
        return;
    }

    struct node *current = start;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = otherList;
}

void Invert()
{
    struct node *prev = NULL, *current = start, *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    start = prev;
}

int main()
{
    InsertAtBegin(5);
    InsertAtBegin(20);
    InsertAtEnd(13);
    InsertAtIndex(80, 3);
    display(); cout << endl;
    
    cout << "Node Updated : " << "\n";
    UpdateNode(50, 3);
    display(); cout << endl;

    cout << "Removed data at index 2: " << RemoveNodeAtIndex(2) << endl;
	display(); cout << endl;

    cout << "Removed data at begin: " << RemoveNodeAtBegin() << endl;
    display(); cout << endl;

    cout << "Removed data at end: " << RemoveNodeAtEnd() << endl;
    display(); cout << endl;

    cout << "Size of list: " << SizeOfList() << endl;

    struct node *otherList = create_node(100);
    otherList->next = create_node(200);
    Concatenate(otherList);
    display(); cout << endl;

    cout << "Reversing the list..." << endl;
    Invert();
    display();

    return 0;
}