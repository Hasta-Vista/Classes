#include <iostream>
#include <numeric>
using namespace std;
class Rational {
private:
    int numerator, denominator;
    void Reduce() {
        int nod = gcd(numerator, denominator);
        numerator /= nod;
        denominator /= nod;
        if (denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        }
    }
public:
    Rational(int num = 0, int den = 1) : numerator(num), denominator(den) {
        Reduce();
    }
    int Numerator() const {
        return numerator;
    }
    int Denominator() const {
        return denominator;
    }
    Rational operator + () {
        return { numerator,denominator };
    }
    Rational operator - () {
        return { -numerator,denominator };
    }
    Rational operator += (const Rational& other) {
        numerator = numerator * other.denominator + other.numerator * denominator;
        denominator *= other.denominator;
        Reduce();
        return *this;
    }
    Rational operator -= (const Rational& other) {
        numerator = numerator * other.denominator - other.numerator * denominator;
        denominator *= other.denominator;
        Reduce();
        return *this;
    }
    Rational operator *= (const Rational& other) {
        numerator *= other.numerator;
        denominator *= other.denominator;
        Reduce();
        return *this;
    }
    Rational operator /= (const Rational& other) {
        numerator *= other.denominator;
        denominator *= other.numerator;
        Reduce();
        return *this;
    }
    Rational operator + (const Rational& other) const {
        int num = numerator * other.denominator + other.numerator* denominator;
        int den = denominator * other.denominator;
        return Rational(num, den);
    }
    Rational operator - (const Rational& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int den = denominator * other.denominator;
        return Rational(num, den);
    }
    Rational operator * (const Rational& other) const {
        int num = numerator * other.numerator;
        int den = denominator * other.denominator;
        return Rational(num, den);
    }
    Rational operator / (const Rational& other) const {
        int num = numerator * other.denominator;
        int den = denominator * other.numerator;
        return Rational(num, den);
    }
    Rational operator + (int value) const {
        Rational frac(value, 1);
        int num = numerator * frac.denominator + frac.numerator * denominator;
        int den = denominator * frac.denominator;
        return Rational(num, den);
    }
    Rational operator - (int value) const {
        Rational frac(value, 1);
        int num = numerator * frac.denominator - frac.numerator * denominator;
        int den = denominator * frac.denominator;
        return Rational(num, den);
    }
    Rational operator * (int value) const {
        return Rational(numerator * value, denominator );
    }
    Rational operator / (int value) const {
        return Rational(numerator, denominator * value);
    }
    bool operator == (const Rational& other) const {
        return other.Numerator() == numerator && other.Denominator() == denominator;
    }
    bool operator != (const Rational& other) const {
        return !(other == *this);
    }
    friend ostream& operator << (ostream& os, const Rational& frac)  {
        os << frac.Numerator() << "/" << frac.Denominator();
        return os;
    }
};
int main()
{
    int numerator, denomirator, num;
    cin >> numerator >> denomirator;
    Rational frac1(numerator, denomirator);
    cin >> numerator >> denomirator;
    Rational frac2(numerator, denomirator);
    cin >> num;
    Rational frac3 = frac1 + frac2; 
    Rational frac4 = frac1 - frac2;
    Rational frac5 = frac1 * frac2; 
    Rational frac6 = frac1 / frac2;
    Rational frac7 = frac1 + num;
    Rational frac8 = frac1 - num;
    Rational frac9 = frac1 * num;
    Rational frac10 = frac1 / num;
    frac1 += frac2; 
    frac1 -= frac2;
    frac1 *= frac2; 
    frac1 /= frac2; 
    cout << "Results:" << endl;
    cout << "frac1 + frac2 = " << frac3 << endl;
    cout << "frac1 - frac2 = " << frac4 << endl;
    cout << "frac1 * frac2 = " << frac5 << endl;
    cout << "frac1 / frac2 = " << frac6 << endl;
    cout << "frac1 + num = " << frac7 << endl;
    cout << "frac1 - num = " << frac8 << endl;
    cout << "frac1 * num = " << frac9 << endl;
    cout << "frac1 / num = " << frac10 << endl;
    cout << "frac1 += frac2 = " << frac3 << endl;
    cout << "frac1 -= frac2 = " << frac4 << endl;
    cout << "frac1 *= frac2 = " << frac5 << endl;
    cout << "frac1 /= frac2 = " << frac6 << endl;
    return 0;
}