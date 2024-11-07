#include <iostream>
#include <numeric>
using namespace std;
class Rational {
private:
    int numerator, denominator;
    void Reduce() {
        int nod = std::gcd(numerator, denominator);
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
    Rational operator + (const Rational& other) {
        numerator = numerator * other.denominator + other.numerator * denominator;
        denominator *= other.denominator;
        Rational result(numerator, denominator);
        Reduce();
        return result;
    }
    Rational operator - (const Rational& other) {
        numerator = numerator * other.denominator - other.numerator * denominator;
        denominator *= other.denominator;
        Rational result(numerator, denominator);
        Reduce();
        return result;
    }
    Rational operator * (const Rational& other) {
        numerator *= other.numerator;
        denominator *= other.denominator;
        Rational result(numerator, denominator);
        Reduce();
        return result;
    }
    Rational operator / (const Rational& other) {
        numerator = numerator * other.denominator;
        denominator = denominator * other.numerator;
        Rational result(numerator, denominator);
        Reduce();
        return result;
    }
    friend ostream& operator << (ostream& os, const Rational& frac) {
        os << endl << frac.Numerator() << endl;
        os << "-" << endl << frac.Denominator();
        return os;
    }
};
int main()
{
    int numerator, denomirator;
    cin >> numerator >> denomirator;
    Rational fraction(numerator, denomirator);
    cin >> numerator >> denomirator;
    Rational fraction2(numerator, denomirator);
    Rational fraction3 = fraction / fraction2;
    cout << fraction3;
    return 0;
}