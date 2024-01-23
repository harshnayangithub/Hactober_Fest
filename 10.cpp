#include <iostream>
#include <cmath>

using namespace std;

class Quadratic {
private:
    int a, b, c;

public:
    Quadratic() {
        a = 0;
        b = 0;
        c = 0;
    }

    Quadratic(int a, int b, int c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    Quadratic &operator+(Quadratic e1) {
        Quadratic *temp = new Quadratic;
        temp->a = a + e1.a;
        temp->b = b + e1.b;
        temp->c = c + e1.c;
        return *temp;
    }

    friend ostream &operator<<(ostream &out, Quadratic &e) {
        out << e.a << "x^2 + " << e.b << "x + " << e.c;
        return out;
    }

    friend istream &operator>>(istream &in, Quadratic &e) {
        cout << "enter the coefficients of polynomial in (a,b,c) format: ";
        in >> e.a >> e.b >> e.c;
        return in;
    }

    float eval(int x) {
        cout<<"value of given polynomial at x = " <<x<< " : ";
        return a * pow(x, 2) + b * x + c;
    }

    void solve() {
        int temp = (b * b) - 4 * a * c;
        float d = sqrt(temp);
        if (d >= 0) {
            cout << "roots of the equation are " << (-b - d) / (2 * a) << " and " << (-b + d) / (2 * a) << endl;
        } else {
            cout << "No real roots exist" << endl;
        }
    }
};

int main() {
    int choice;
    Quadratic p1, p2, p, eqn, sum; 
    do {
        cout << "\nMENU" << endl;
        cout << "1 two polynomials Addition\n2 Value of a polynomial at given value of x\n3 Calculate roots of a eqn\n4 exit\n";
        cout << "enter a choice: ";
        cin >> choice;
        cout<<endl;
        switch (choice) {
            case 1:
                cout << "-----polynomial 1-----\n";
                cin >> p1;
                cout << "-----polynomial 2-----\n";
                cin >> p2;
                cout << "sum is : ";
                sum = p1 + p2;
                cout << sum;
                cout<<endl;
                break;
            case 2:
                cin >> p;
                cout << "enter value of x : ";
                int x;
                cin >> x;
                cout << p.eval(x);
                cout<<endl;
                break;
            case 3:
                cin >> eqn;
                eqn.solve();
                break;
            case 4:
                cout<<"------exiting------";
                break;
            default:
                cout << "enter a valid choice\n";
                break;
        }
    } while (choice != 4);
    return 0;
}
