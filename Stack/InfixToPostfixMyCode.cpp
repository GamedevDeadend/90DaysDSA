#include<iostream>
#include<stack>
using namespace std;


int prec(char a)
{
    switch (a)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
    case '%':
        return 2;

    case '^':
        return 3;
    }
}

bool IsOperand(char a)
{
    switch (a)
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '^':
            return false;
        default :
            return true;
    }
}
string InToPost(string infix)
{
   stack<char> postfix;
   string res = "";
//    cout<<res<<"Start"<<infix.length();
//    cout<<endl;
   int i = 0;
//    while(i<res.length())
while( i < infix.length() )
   {
        // cout<<res<<"Loop";
        // cout<<endl;
        if(infix[i]=='(')
        {
            postfix.push(infix[i]);
            // cout<<res;
            // cout<<endl;
            i++;
        }

        else if(infix[i]==')')
        {
            while(postfix.top() != '(')
            {
                res += postfix.top();
                postfix.pop();
            }
            i++;
            // cout<<res;
            // cout<<endl;
        }

        if(IsOperand(infix[i]))
        {
            res += infix[i];
            i++;
            // cout<<res;
            // cout<<endl;
        }

        else
        {
            if(postfix.empty())
            {
                postfix.push(infix[i]);
                i++;
            }

            else
            {
                if(prec(infix[i])>prec(postfix.top()))
                {
                    postfix.push(infix[i]);
                    i++;
                }

                else
                {
                    while (!IsOperand(postfix.top()))
                    {
                        res += postfix.top();
                        postfix.pop();
                    }
                    i++;
                }
            }
        }
   }

    while (!postfix.empty())
    {
        if(postfix.top() == '(')
        {
            postfix.pop();
        }
            res += postfix.top();
            postfix.pop();
    }
    
    // cout<<res;
    // cout<<endl;
    return res;
}

int main()
{
   string infix = "a+b*(c^d-e)^(f+g*h)-i";
   cout<<"result: "<<InToPost(infix);
}