#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
} *front = nullptr, *rear = nullptr;

void enqueue(int x)
{
    node *temp;
    temp = new node;
    temp->data = x;
    if (front == nullptr)
    {
        front = rear = temp;
        rear->next = front;
    }

    else
    {
        rear->next = temp;
        rear = temp;
        rear->next = front;
    }
}

void display()
{
    node *temp;
    temp = front;

    if (front == nullptr && rear == nullptr)
    {
        cout << "Queue is empty" << endl;
    }

    else
    {
        while (temp->next != front)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }

        cout << temp->data;
    }
}

void dequeue()
{
    node *temp;
    temp = front;

    if (front == nullptr && rear == nullptr)
    {
        cout << "Queue is Empty" << endl;
    }

    else if (front == rear)
    {
        front = rear = nullptr;
        cout << "Deleted: " << temp->data;
        delete (temp);
    }

    else
    {
        front = front->next;
        rear->next = front;
        delete (temp);
    }
}

int main()
{
    enqueue(34);
    enqueue(10);
    enqueue(34);
    enqueue(23);
    enqueue(34);
    display();
    dequeue();
}