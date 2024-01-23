#include <iostream>
using namespace std;
#define size 100

class Stack {
    char *arr;
    int top;

public:
    Stack() {
        arr = new char[size];
        top = -1;
    }
    void push(char c) {
        if (top == size - 1) {
            cout << "Stack Overflow";
            return;
        }
        arr[++top] = c;
    }
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return;
        }
        top--;
    }
    char Top() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
        }
        return arr[top];
    }
    bool isEmpty() {
        return top == -1;
    }
};

int prec(char c) {
    if (c == '^') {
        return 3;
    } else if (c == '/' || c == '*') {
        return 2;
    } else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void infixtoPostfix(string expr) {
    string res = "";
    Stack st;

    for (int i = 0; i < expr.length(); i++) {
        char c = expr[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            res += c;
        } else if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            while (st.Top() != '(') {
                res += st.Top();
                st.pop();
            }
            st.pop();
        } else {
            while (!st.isEmpty() && prec(c) <= prec(st.Top())) {
                res += st.Top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.isEmpty()) {
        res += st.Top();
        st.pop();
    }

    cout << "Postfix Expression: " << res << endl;
}

int main() {
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Convert Infix to Postfix\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To clear the newline character from the input buffer

        switch (choice) {
            case 1: {
                string expression;
                cout << "Enter the Infix Expression: ";
                getline(cin, expression);
                infixtoPostfix(expression);
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
