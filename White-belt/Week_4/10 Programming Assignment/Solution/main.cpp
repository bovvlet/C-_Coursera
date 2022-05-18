#include <iostream>
#include <algorithm>
#include <exception>

using namespace std;

int gcd(int a, int b) {
	return abs(__gcd(a, b));
}

class Rational {
public:
	Rational() {
		numerator = 0;
		denominator = 1;
	};
	void beuty_Rational() {
		if (numerator == 0){
			denominator = 1;
		}
		if (denominator < 0) {
			numerator = -numerator;
			denominator = -denominator;
		}
		int common_divisor = gcd(numerator, denominator);
		numerator /= common_divisor;
		denominator /= common_divisor;
	}
	Rational(int numerator, int denominator) {
		if (denominator == 0)
			throw invalid_argument("denominator can't be zero");
		this->numerator = numerator;
		this->denominator = denominator;
		beuty_Rational();
	}
	int Numerator() const {
		return numerator;
	}
	int Denominator() const {
		return denominator;
	}
private:
	int numerator, denominator;
};

Rational operator* (const Rational& a, const Rational& b) {
	return Rational(a.Numerator() * b.Numerator(), 
					a.Denominator() * b.Denominator());
}

Rational operator/ (const Rational& a, const Rational& b) {
	if (b.Numerator() == 0){
        throw domain_error("we can't divide by zero");
    }
    Rational b_reversed = Rational(b.Denominator(), b.Numerator());
	return a * b_reversed;
}
int main() {
	return 0;
}