#include<bits/stdc++.h>
using namespace std;

#define size 100
template<class T>
class Stack{
    T arr[size];
    public:
    int t;
    Stack() {
        t = -1;
    }
    T top() {
        return arr[t];
    }
    void push(T x) {
        if(t == size-1) {
            cout << "Stack Overflow\n";
        }
        else {
            t ++;
            arr[t] = x;
        }
    }
    T pop() {
        if(t < 0) {
            cout << "Stack Underflow\n";
            return -1;
        }
        T x = arr[t];
        t --;
        return x;
    }
    void display() {
        for(int i = 0; i <= t; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    bool isEmpty() {
        if(t < 0) {
            return 1;
        }
        return 0;
    }
};

bool op(char x) {
    if(x == '+' or x == '-' or x == '*' or x == '/') {
        return 1;
    }
    return 0;
}

void infixToPostfix(string s, vector<char> &ans) {
    map<char, int> map1;
    map1['+'] = 1;
    map1['-'] = 1;
    map1['*'] = 2;
    map1['/'] = 2; 
    Stack<char> stk;
    bool f = 0;
    for(auto i:s) {
        if(!op(i)) {
            if(i == '(') {
                stk.push(i);
            }
            else if(i == ')') {
                while(!stk.isEmpty()) {
                    if(stk.top() != '(') {
                        ans.push_back(stk.top());
                    }
                    stk.pop();
                }
            }
            else {
                ans.push_back(i);
            }
        }
        else {
            if(map1[stk.top()] > map1[i]) {
                ans.push_back(stk.pop());
            }
            stk.push(i);
        }
    }
    while(!stk.isEmpty()) {
        if(stk.top() != '(') {
            ans.push_back(stk.top());
        }
        stk.pop();
    }
}

float postfixEvaluate(string s) {
    Stack<float> stk;
    for(auto i:s) {
        if(!op(i)) {
            stk.push(i-48);
        }
        else if(op(i)) {
            float y = stk.pop();
            float x = stk.pop();
            float z;
            if(i == '+') {
                z = x + y;
            }
            else if(i == '-') {
                z = x - y;
            }
            else if(i == '*') {
                z = x * y;
            }
            else if(i == '/') {
                z = x / y;
            }
            stk.push(z);
        }
    }
    return stk.pop();
}

int main() {
    cout << "\n-----------PROGRAM FOR INFIX TO POSTFIX CONVERSION AND EVALUATION----------------\n";
    cout << "\nMENU:\n1. Infix to Postfix\n2. Postfix Evaluation\n3. Exit\n";
    do {
        cout << "\nEnter choice: ";
        int n;
        cin >> n;
        switch(n) {
            case 1: {
                cout << "\n--------------INFIX -> POSTFIX-----------------\n";
                vector<char> ans;
                string s;
                cout << "Enter the infix expression: ";
                cin >> s;
                infixToPostfix(s, ans);
                cout << "Postfix expression: ";
                for(auto i:ans) {
                    cout << i;
                }
                cout << endl;
                break;
            }
            case 2: {
                cout << "\n-----------------POSTFIX EVALUATION------------------\n";
                cout << "Enter the postfix expression: ";
                string s;
                cin >> s;
                cout << "Value of the given PostFix expression: " << fixed << setprecision(2) << postfixEvaluate(s) << endl; 
                break; 
            }
            case 3:
                cout << "\n----------------EXITING---------------------\n";
                exit(0);       
        }
    }
    while(true);
}
 