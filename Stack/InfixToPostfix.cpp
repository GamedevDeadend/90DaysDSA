 #include<iostream>
 #include<stack>
 using namespace std;

 int prec(char c) 
{
        if (c == '^')
            return 3;
        else if (c == '/' || c == '*')
            return 2;
        else if (c == '+' || c == '-')
            return 1;
        else
            return -1;
}

 string infixToPostfix(string s) 
 {
        stack<char> st; // For stack operations, we are using C++ built in stack
        string result;

        for (int i = 0; i < s.length(); i++) 
        {
            char c = s[i];

            // If the scanned character is
            // an operand, add it to output string.
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
                (c >= '0' && c <= '9'))
                result += c;

            // If the scanned character is an
            // â€˜(â€˜, push it to the stack.
            else if (c == '(')
                st.push('(');

            // If the scanned character is an â€˜)â€™,
            // pop and to output string from the stack
            // until an â€˜(â€˜ is encountered.
            else if (c == ')')
            {
                while (st.top() != '(') {
                    result += st.top();
                    st.pop();
                }
                st.pop();
            }

            // If an operator is scanned
            else {
                while (!st.empty() && prec(s[i]) <= prec(st.top())) {
                    result += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }

        // Pop all the remaining elements from the stack
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        return result;
}

int main()
{
    string exp = "((A+B)-C*(D/E))+F";
    cout<<"Result: "<<infixToPostfix(exp);
}


// Step to convert infix to postfix
// if '(' then push to stack
// if operand then store in res string
// if ')' keep pop and send to res until '(' is found
// if operator is found 
                // *if stack is empty then push it
                // *compare with top operator
                    //if higher precedence than stack push
                    //else keep poping and sending to res until higher operator is found is found
//once expression is finished make sure stack is empty and send all elemnts to res