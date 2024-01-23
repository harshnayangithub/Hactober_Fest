#include <iostream>
using namespace std;
#define size 10

class stackexp {
    int top;
    char stk[size];

public:
    stackexp() {
        top = -1;
    }
    void push(char);
    char pop();
    int isfull();
    int isempty();
};

void stackexp::push(char x) {
    top = top + 1;
    stk[top] = x;
}

char stackexp::pop() {
    char s;
    s = stk[top];
    top = top - 1;
    return s;
}

int stackexp::isfull() {
    if (top == size)
        return 1;
    else
        return 0;
}

int stackexp::isempty() {
    if (top == -1)
        return 1;
    else
        return 0;
}

bool isBalanced(const char* exp) {
    stackexp s1;
    int i = 0;

    if ((exp[0] == ')') || (exp[0] == ']') || (exp[0] == '}')) {
        cout << "\nInvalid Expression.....\n";
        return false;
    } else {
        while (exp[i] != '\0') {
            char ch = exp[i];
            switch (ch) {
                case '(':
                case '[':
                case '{':
                    s1.push(ch);
                    break;
                case ')':
                    if (s1.pop() != '(')
                        return false;
                    break;
                case ']':
                    if (s1.pop() != '[')
                        return false;
                    break;
                case '}':
                    if (s1.pop() != '{')
                        return false;
                    break;
            }
            i = i + 1;
        }
    }
    return s1.isempty();
}

int main() {
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Check Parentheses\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                char exp[20];
                cout << "Enter the expression to check for balanced parentheses: ";
                cin >> exp;
                if (isBalanced(exp))
                    cout << "Expression is well parenthesized.\n";
                else
                    cout << "Invalid Expression or not well parenthesized.\n";
                break;
            }
            case 2:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please enter a valid choice.\n";
        }
    } while (choice != 2);

    return 0;
}
