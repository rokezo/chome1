#include <iostream>
using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;
public:
    Fraction() : numerator(0), denominator(1) {}

    Fraction(int num, int den) : numerator(num), denominator(den) {}
    void input() {
        cout << "Enter numerator: ";
        cin >> numerator;
        cout << "Enter denominator: ";
        cin >> denominator;
    }

    void output() {
        cout << numerator << "/" << denominator << endl;
    }

    int operation(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void reduce() {
        int operationValue = operation(numerator, denominator);
        numerator /= operationValue;
        denominator /= operationValue;
    }

    Fraction add(const Fraction& other) {
        int num = numerator * other.denominator + other.numerator * denominator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }
    Fraction sub(const Fraction& other) {
        int num = numerator * other.denominator - other.denominator * denominator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

    Fraction mul(const Fraction& other) {
        int num = numerator * other.numerator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }
    Fraction div(const Fraction& other) {
        int num = numerator * other.denominator;
        int den = denominator * other.numerator;
        return Fraction(num, den);
    }

};



int main()
{
    Fraction f1, f2, result;

    cout << "Enter one Fraction: " << endl;
    f1.input();

    cout << "Enter two Fraction: " << endl;
    f2.input();
    
    cout << "Result add: " << endl;
    result = f1.add(f2);
    result.output();

    cout << "Result sub: " << endl;
    result = f1.sub(f2);
    result.output();

    cout << "Result mul: " << endl;
    result = f1.mul(f2);
    result.output();

    cout << "Result div: " << endl;
    result = f1.div(f2);
    result.output();
    return 0;
}

