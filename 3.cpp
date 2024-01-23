#include<iostream>
using namespace std;

class Complex
{
    float real, img;

public:
    Complex()
    {
        real = 0.0f;
        img = 0.0f;
    }

    Complex(float a, float b)
    {
        real = a;
        img = b;
    }

    Complex &operator+(Complex c1)
    {
        Complex *temp = new Complex;
        temp->real = real + c1.real;
        temp->img = img + c1.img;
        return *temp;
    }

    Complex operator-(Complex c1)
    {
        Complex temp;
        temp.real = real - c1.real;
        temp.img = img - c1.img;
        return temp;
    }

    Complex operator*(Complex c1)
    {
        Complex temp;
        temp.real = (real * c1.real) - (img * c1.img);
        temp.img = (img * c1.real) + (real * c1.img);
        return temp;
    }

    friend ostream &operator<<(ostream &out, Complex &c)
    {
        out << c.real << " + " << c.img << " i";
        return out;
    }

    friend istream &operator>>(istream &in, Complex &c)
    {
        in >> c.real >> c.img;
        return in;
    }
};

int main()
{
    Complex c1, c2, c3;
    int choice;
    char ans;
    do
    {
        cout << "\n************* MENU ************\n";
        cout << "\n\t1.Addition\n\t2.Subtraction\n\t3.Multiplication\n\t5.Exit";
        cout << "\n\nEnter your choice: ";
        cin >> choice;
        if (choice == 5)
            break;

        cout << "Enter real and img part of the first complex number\n";
        cin >> c1;
        cout << "Enter real and img part of the second complex number\n";
        cin >> c2;

        switch (choice)
        {
        case 1:
            c3 = c1 + c2;
            cout << "\n\nAddition is: ";
            cout << c3;
            break;
        case 2:
            c3 = c1 - c2;
            cout << "\n\nSubtraction is: ";
            cout << c3;
            break;
        case 3:
            c3 = c1 * c2;
            cout << "\n\nMultiplication is: ";
            cout << c3;
            break;
        default:
            cout << "\nWrong choice";
        }

    } while (true);

    cout << "\nExiting the program.\n";
    return 0;
}
