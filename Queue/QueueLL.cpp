
#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;
} *q = nullptr, *front = nullptr, *rear = nullptr;

void enqueue(int x)
{
    node* temp = new node;
    temp->data = x;

    // if(!front && !rear)
    // {
        // q = temp;
    // }

	if(rear == nullptr)
	{
		front = rear = temp;      
		return;
	}		
		rear->next = temp;
        rear = temp;
}

int peek()
{
    return rear->data;
}

int deQueue()
    {
        int x;
        // If queue is empty, return NULL.
        if (front == NULL)
            return -1;
        // Store previous front and
        // move front one node ahead
        node* temp = front;
        x = front->data;
        front = front->next;
        
        // If front becomes NULL, then
        // change rear also as NULL
        if (front == NULL)
            rear = NULL;

        delete (temp);
        return x;
    }

    void display()
    {
        while(rear != front)
        {
            cout<<front->data;
            deQueue();
        } 
    }



int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(50);
    // cout<<deQueue();
    // cout<<deQueue();
    // cout<<deQueue();
    display();
}