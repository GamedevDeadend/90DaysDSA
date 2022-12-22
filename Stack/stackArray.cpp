#include<iostream>
using namespace std;

//template <class t>
class stack
{
	int *s;
	int top;
	int size;
	
	public:
		
		stack(int size): size(size), top(-1), s(new int[size]){}
		
		void  push(int x)
		{
			if(top == size-1)
			{
				cout<<"Stack Overflow Error"<<endl;
			}
			
			else
			{
				top++;
				s[top] = x;
			}
		}
		
		int pop()
		{
			int x;
			if(top == -1)
			{
				cout<<"stack underflow"<<endl;
				return -1;
			}
			else
			{
				x = s[top];
				top--;
				return x;
			}
		}
		
		void display()
		{
			for(int i  = top ; i>=0; i--)
			{
				cout<<s[i]<<" ";
			}
			cout<<endl;
		}
	
};

int main()
{
	stack s(2);
	s.push(10);
	s.push(20);
	cout<<"delete "<<s.pop()<<endl;
	s.push(30);
	s.display();
}
