#include<iostream>
using namespace std;

class Queue
{
	int *Q;
	int front,rear;
	int size;
	public:
		//Constructor and intializer list
		Queue(int x): front(-1), rear(-1) ,size(x), Q(new int[size]){}
		
		void enqueue(int x)
		{
			if(rear == size-1)
			{
				cout<<"Overflow"<<endl;
				return;
			}
			
			else
			{
				rear++;
				Q[rear] = x;
			}
		}
		
		void print()
		{
			for(int i = front+1; i <= rear; i++)
			{
				cout<<Q[i]<<"\n";
			}
		}
		
		int dequeue()
		{
			int x;
			if(rear == front)
			{
				cout<<"Underflow"<<endl;
				return -1;
			}
			else
			{
				front++;
				x = Q[front];
			}
			return x;
		}
};

int main()
{
	Queue Q(3);
	Q.enqueue(100);
	Q.enqueue(200);
	Q.enqueue(300);
	Q.print();
}