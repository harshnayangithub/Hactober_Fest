#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isWellParenthesized(string &expression)
{
    stack<char> parentheses;

    for (auto ch : expression)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            parentheses.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
                if (parentheses.empty() ||
                    (ch == ')' && parentheses.top() != '(') ||
                    (ch == '}' && parentheses.top() != '{') ||
                    (ch == ']' && parentheses.top() != '['))
            {
                return false;
            }
            parentheses.pop();
        }
    }

    return parentheses.empty();
}

int main()
{
    int choice;
    string expression;

    do
    {
        cout << "\n------ Menu ------" << endl;
        cout << "1. Check Parentheses\n";
        cout << "2. Exit\n";
        cout << "Enter your choice (1-2): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the expression: ";
            cin >> expression;
            if (isWellParenthesized(expression))
            {
                cout << "Expression is well-parenthesized.\n";
            }
            else
            {
                cout << "Expression is not well-parenthesized.\n";
            }
            break;
        case 2:
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please enter 1 or 2.\n";
        }

    } while (choice != 2);

    return 0;
}
