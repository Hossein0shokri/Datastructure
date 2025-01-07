#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *prev;
    struct node *next;
} *start = NULL;

node *create_node(int val)
{
    struct node *n = new (struct node);

    n->data = val;
    n->prev = NULL;
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
        start->prev = n;
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
    n->prev = s;
}

void InsertAtIndex(int data, int index)
{
    struct node *n = create_node(data);
    if (n == NULL)
        return;

    if (index == 1)
    {
        n->next = start;
        if (start != NULL)
            start->prev = n;
        start = n;
        return;
    }

    struct node *s = start;
    int i = 1;

    while (s != NULL && i < index - 1)
    {
        s = s->next;
        i++;
    }

    if (s == NULL)
    {
        cout << "Position out of range" << endl;
        delete n;
        return;
    }

    n->next = s->next;
    s->next->prev = n;
    s->next = n;
    n->prev = s;
    
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
        cout << t->data << "<->";
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
        return -1;
    }

    if (current->prev != NULL)
        current->prev->next = current->next;
    else
        start = current->next;

    if (current->next != NULL)
        current->next->prev = current->prev;

    int data = current->data;
    delete current;
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
    if (start != NULL)
        start->prev = NULL;
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

    struct node *current = start;

    while (current->next != NULL)
    {
        current = current->next;
    }

    if (current->prev != NULL)
        current->prev->next = NULL;
    else
        start = NULL;

    int data = current->data;
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

void Invert()
{
    struct node *current = start, *temp = NULL;

    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL)
        start = temp->prev;
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
    otherList->prev = current;
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
    otherList->next->prev = otherList;
    Concatenate(otherList);
    display(); cout << endl;

    cout << "Reversing the list..." << endl;
    Invert();
    display();

    return 0;
}