#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void push(Node *&head, int value);
int pop(Node *&head);
void display(Node *head);

int main()
{
    Node *head = nullptr;

    display(head);
    cout << pop(head) << "\n";

    push(head, 10);
    push(head, 20);
    display(head);

    cout << "Removed element: " << pop(head) << "\n";
    display(head);
    pop(head);
    pop(head);

    return 0;
}

void push(Node *&head, int value)
{
    Node *newNode = new Node{value, head};
    head = newNode;
}

int pop(Node *&head)
{
    if (head == nullptr)
    {
        cout << "List is empty\n";
        return -1;
    }

    int value = head->data;
    Node *temp = head;
    head = head->next;
    delete temp;

    return value;
}

void display(Node *head)
{
    if (head == nullptr)
    {
        cout << "List is empty\n";
        return;
    }

    Node *curr = head;
    while (curr != nullptr)
    {
        cout << curr->data << " -> ";
        curr = curr->next;
    }
    cout << "NULL\n";
}