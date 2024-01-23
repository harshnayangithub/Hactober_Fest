#include <iostream>
#include <cmath>

using namespace std;

// Structure to represent a term in a polynomial
struct Term {
    int coefficient;
    int exponent;
};

// Function to read a polynomial
void readPolynomial(Term polynomial[], int degree) {
    cout << "Enter the degree of the polynomial: ";
    cin >> degree;

    cout << "Enter the coefficients for each term (from highest degree to lowest):\n";

    for (int i = degree; i >= 0; i--) {
        cout << "Coefficient for x^" << i << ": ";
        cin >> polynomial[i].coefficient;
        polynomial[i].exponent = i;
    }
}

// Function to display a polynomial
void displayPolynomial( Term polynomial[], int degree) {
    for (int i = degree; i >= 0; i--) {
        if (polynomial[i].coefficient != 0) {
            cout << polynomial[i].coefficient;
            if (polynomial[i].exponent > 0) {
                cout << "x^" << polynomial[i].exponent;
            }
            if (i > 0 && polynomial[i - 1].coefficient > 0) {
                cout << " + ";
            }
        }
    }
    cout << endl;
}

// Function to evaluate a polynomial for a given value of x
int evaluatePolynomial(const Term polynomial[], int degree, int x) {
    int result = 0;
    for (int i = degree; i >= 0; i--) {
        result += polynomial[i].coefficient * pow(x, polynomial[i].exponent);
    }
    return result;
}

// Function to add two polynomials
void addPolynomials(const Term polynomial1[], const Term polynomial2[], Term result[], int degree1, int degree2) {
    int maxDegree = max(degree1, degree2);

    for (int i = 0; i <= maxDegree; i++) {
        result[i].coefficient = 0;
        result[i].exponent = i;

        if (i <= degree1) {
            result[i].coefficient += polynomial1[i].coefficient;
        }

        if (i <= degree2) {
            result[i].coefficient += polynomial2[i].coefficient;
        }
    }
}

// Function to multiply two polynomials
void multiplyPolynomials(const Term polynomial1[], const Term polynomial2[], Term result[], int degree1, int degree2) {
    for (int i = 0; i <= degree1 + degree2; i++) {
        result[i].coefficient = 0;
        result[i].exponent = i;

        for (int j = 0; j <= min(degree1, i); j++) {
            if (i - j <= degree2) {
                result[i].coefficient += polynomial1[j].coefficient * polynomial2[i - j].coefficient;
            }
        }
    }
}

int main() {
    const int MAX_DEGREE = 100; // Maximum degree of a polynomial

    Term polynomial1[MAX_DEGREE + 1], polynomial2[MAX_DEGREE + 1], result[MAX_DEGREE * 2 + 1];
    int degree1, degree2, choice, x;

    do {
        cout << "\n------ Menu ------" << endl;
        cout << "1. Read Polynomial\n2. Solve Polynomial for x=3\n3. Addition of Two Polynomials\n";
        cout << "4. Multiplication of Two Polynomials\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nReading Polynomial 1:" << endl;
                readPolynomial(polynomial1, degree1);
                cout << "Polynomial 1: ";
                displayPolynomial(polynomial1, degree1);

                cout << "\nReading Polynomial 2:" << endl;
                readPolynomial(polynomial2, degree2);
                cout << "Polynomial 2: ";
                displayPolynomial(polynomial2, degree2);
                break;

            case 2:
                cout << "Enter the value of x: ";
                cin >> x;
                cout << "Polynomial 1 evaluated at x=" << x << ": " << evaluatePolynomial(polynomial1, degree1, x) << endl;
                cout << "Polynomial 2 evaluated at x=" << x << ": " << evaluatePolynomial(polynomial2, degree2, x) << endl;
                break;

            case 3:
                addPolynomials(polynomial1, polynomial2, result, degree1, degree2);
                cout << "\nResult of Addition: ";
                displayPolynomial(result, max(degree1, degree2));
                break;

            case 4:
                multiplyPolynomials(polynomial1, polynomial2, result, degree1, degree2);
                cout << "\nResult of Multiplication: ";
                displayPolynomial(result, degree1 + degree2);
                break;

            case 5:
                cout << "Exiting the program. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
        }
    } while (choice != 5);

    return 0;
}
