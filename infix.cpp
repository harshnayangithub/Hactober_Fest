#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int getPrecedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    return 0; // For other characters (operands)
}

string infixToPostfix(const string &infix)
{
    stack<char> s;
    string postfix = "";

    for (char ch : infix)
    {
        if (isalnum(ch))
        {
            postfix += ch;
        }
        else if (ch == '(')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // Remove the '('
        }
        else if (isOperator(ch))
        {
            while (!s.empty() && getPrecedence(ch) <= getPrecedence(s.top()))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int evaluatePostfix(const string &postfix)
{
    stack<int> s;

    for (char ch : postfix)
    {
        if (isalnum(ch))
        {
            s.push(ch - '0'); // Convert char to int
        }
        else if (isOperator(ch))
        {
            int operand2 = s.top();
            s.pop();
            int operand1 = s.top();
            s.pop();

            switch (ch)
            {
            case '+':
                s.push(operand1 + operand2);
                break;
            case '-':
                s.push(operand1 - operand2);
                break;
            case '*':
                s.push(operand1 * operand2);
                break;
            case '/':
                s.push(operand1 / operand2);
                break;
            }
        }
    }

    return s.top();
}

int main()
{
    string infix, postfix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    int result = evaluatePostfix(postfix);
    cout << "Result after evaluation: " << result << endl;

    return 0;
}
