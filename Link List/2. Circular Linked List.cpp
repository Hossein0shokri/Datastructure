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
        n->next = start;
    }
    else
    {
        struct node *temp = start;
        while (temp->next != start)
        {
            temp = temp->next;
        }
        n->next = start;
        start = n;
        temp->next = start;
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
        n->next = start;
        return;
    }

    struct node *temp = start;
    while (temp->next != start)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = start;
}

void InsertAtIndex(int data, int index)
{
    struct node *n = create_node(data);
    if (n == NULL)
        return;

    if (index == 1)
    {
        InsertAtBegin(data);
        return;
    }

    struct node *temp = start;
    int i = 1;
    while (i < index - 1 && temp->next != start)
    {
        temp = temp->next;
        i++;
    }

    if (i == index - 1)
    {
        n->next = temp->next;
        temp->next = n;
    }
    else
    {
        cout << "Position out of range" << endl;
        delete n;
    }
}

void UpdateNode(int data, int index)
{
    if (start == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    struct node *temp = start;
    int position = 1;

    do
    {
        if (position == index)
        {
            temp->data = data;
            return;
        }
        temp = temp->next;
        position++;
    } while (temp != start);

    cout << "Position out of range." << endl;
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

    if (start->next == start)
    {
        start = NULL;
        delete temp;
        return data;
    }

    struct node *last = start;
    while (last->next != start)
    {
        last = last->next;
    }

    start = start->next;
    last->next = start;
    delete temp;
    return data;
}

int RemoveNodeAtIndex(int index)
{
    if (start == NULL)
    {
        cout << "The list is empty." << endl;
        return -1;
    }

    struct node *current = start, *previous = NULL;
    int position = 1;

    if (index == 1)
    {
        return RemoveNodeAtBegin();
    }

    do
    {
        previous = current;
        current = current->next;
        position++;
    } while (current != start && position < index);

    if (current == start || position != index)
    {
        cout << "Position out of range." << endl;
        return -1;
    }

    previous->next = current->next;
    int data = current->data;
    delete current;
    return data;
}

int RemoveNodeAtEnd()
{
    if (start == NULL)
    {
        cout << "The list is empty." << endl;
        return -1;
    }

    struct node *temp = start, *prev = NULL;
    while (temp->next != start)
    {
        prev = temp;
        temp = temp->next;
    }

    int data = temp->data;

    if (prev == NULL)
    {
        start = NULL;
    }
    else
    {
        prev->next = start;
    }

    delete temp;
    return data;
}

int SizeOfList()
{
    if (start == NULL)
        return 0;

    struct node *temp = start;
    int size = 0;
    do
    {
        size++;
        temp = temp->next;
    } while (temp != start);

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
        struct node *temp = otherList;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = start;
        return;
    }

    struct node *temp = start;
    while (temp->next != start)
    {
        temp = temp->next;
    }
    temp->next = otherList;

    struct node *last = otherList;
    while (last->next != NULL && last->next != otherList)
    {
        last = last->next;
    }
    last->next = start;
}

void Invert()
{
    if (start == NULL || start->next == start)
        return;

    struct node *prev = NULL, *current = start, *next = NULL;
    struct node *last = start;

    do
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != start);

    start->next = prev;
    start = prev;
}

void display()
{
    if (start == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    struct node *temp = start;
    cout << "Elements: ";
    do
    {
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != start);
    cout << endl;
}

int main()
{
    InsertAtBegin(5);
    InsertAtBegin(20);
    InsertAtEnd(13);
    InsertAtIndex(80, 3);
    display(); cout << endl;

    cout << "Node Updated : \n";
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
    otherList->next->next = otherList;
    Concatenate(otherList);
    display(); cout << endl;

    cout << "Reversing the list..." << endl;
    Invert();
    display();

    return 0;
}