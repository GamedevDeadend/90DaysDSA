#include <iostream>
using namespace std;

class Dequeue
{
    int size;
    int front,rear;
    int *q;

    public:

        Dequeue(int size)
        {
            this->size = size;
            q= new int[size];
            front = rear = -1;
        }

        void enqueue_rear(int x)
        {
            if(rear == (size - 1))
            {
                cout<<"Queue is Overflow"<<endl;
            }
            else
            {
                rear += 1;
                q[rear] = x;
            }
        }

        void enqueue_front(int x)
        {
            if(front < 0)
            {
                cout<<"Queue is Underflow"<<endl;
            }
            else
            {
                front--;
                q[front] = x; 
            }
        }

        int dequeue_rear()
        {
            int x;
            if(rear == -1)
            {
                cout<<"Queue is Underflow"<<endl;
            }

            else
            {
                x = q[rear];
                rear -= 1;
            }

            return x;
        }

        int dequeue_front()
        {
            int x;
            if(front > rear || front == rear == -1)
            {
                cout<<"Queue is underflow"<<endl;
            }

            else
            {
                x = q[front];
                front += 1;
            }

            return x;
        }

        void display()
        {
            for(int i  = 0; i < size; i++)
            {
                int temp = q[i];
                cout<<q[i]<<endl;
            }
        }
};


int main() 
{
    Dequeue q(10);
    for(int i  = 0; i<10; i++)
    {
        q.enqueue_front(10);
    }
    q.display();
}