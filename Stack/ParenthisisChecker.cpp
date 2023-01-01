#include <iostream>
#include <stack>
using namespace std;

// Parenthesis Checking Rules:-
// If Opening Bracket then push to stack
// Else Closing Bracket then check top element from stack

// Function to check for opening Brackets
inline bool IsOpening(char c)
{
    return (c == '(' || c == '{' || c == '[') ? true : false;
}


// Fuction to Check Match of  Open and Closed Bracket from Stack and String 
inline bool IsMatching(char& a, char& b)
{
    return  ((a == '(' && b == ')') || (a == '{' && b == '}') ||  (a == '[' && b == ']'))? true : false;
}


//Main Function To Check Parenthesis Validation
bool IsParenthesisMatching(string str)
{
    stack<char> s;      //temp stack to store open brackets

    for (int i = 0; i < str.length(); i++)
    {
        if (IsOpening(str[i]))
        {
            s.push(str[i]);     //Pushing Opening Brackets
        }
        else
        {
            if (s.empty())
            {
                return false;       //checking if stack is already empty means no opening brackets in stack
            }

            else if (!IsMatching(s.top(), str[i]))
            {
                cout<<s.top();          //condition if parenthesis doesn't match
                cout<<str[i];
                return false;
            }
            else
            {
                s.pop();    //Deleting open Bracket if Match is found
            }
        }
    }

    return s.empty();  //After going through whole string if any opening brackets were found then return false as their closing brackets were not found
}

int main()
{
    string check = "({[]})";
    IsParenthesisMatching(check) ? cout << "Success" : cout << "Fail";
}