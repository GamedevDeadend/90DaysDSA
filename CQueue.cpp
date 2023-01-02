#include <iostream>
using namespace std;


class CQueue
{
    private:

        int size;
        int *Q;
        int rear;
        int front;
    
    public:

    CQueue(int size):size(size),front(-1), rear(-1),Q(new int [size]){}
    int enqueue(int x)
    {

        if((rear+1)%size == front)
        {
            cout<<"Queue is full"<<endl;
        }

        rear = (rear+1)%size;
        Q[rear] = x;
    }

    int dequeue()
    {
        int x;
        if(front == rear)
        {
            cout<<"Empty Queue"<<endl;
        }
        else
        {
            x = Q[front];
            front = (front+1)%size;
        }

        return x;
    }

    void display()
    {
        for (int i = front; i <= rear; i++)
        {
            cout<<Q[i]<<endl;
        }
        
    }
};
int main() 
{
   CQueue q(10);
        q.enqueue(3);
        q.enqueue(1);
        q.enqueue(2);
        q.display();
}