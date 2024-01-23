#include <iostream>
#include <stack>

using namespace std;

string addBinary(const string& a, const string& b) {
    stack<char> result;
    int carry = 0;

    int i = a.size() - 1;
    int j = b.size() - 1;

    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;

        if (i >= 0) {
            sum += a[i] - '0';
            i--;
        }

        if (j >= 0) {
            sum += b[j] - '0';
            j--;
        }

        result.push((sum % 2) + '0');
        carry = sum / 2;
    }

    string finalResult;
    while (!result.empty()) {
        finalResult += result.top();
        result.pop();
    }

    return finalResult;
}

int main() {
    string binary1, binary2;

    cout << "Enter the first binary number: ";
    cin >> binary1;

    cout << "Enter the second binary number: ";
    cin >> binary2;

    string sum = addBinary(binary1, binary2);

    cout << "Sum of " << binary1 << " and " << binary2 << " is: " << sum << endl;

    return 0;
}
