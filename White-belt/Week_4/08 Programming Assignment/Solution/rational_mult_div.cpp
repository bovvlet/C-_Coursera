#include <iostream>
#include <algorithm>

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

bool operator== (const Rational& a, const Rational& b) {
	return a.Numerator() == b.Numerator() and
		   a.Denominator() == b.Denominator();
}

Rational operator* (const Rational& a, const Rational& b) {
	return Rational(a.Numerator() * b.Numerator(), 
					a.Denominator() * b.Denominator());
}

Rational operator/ (const Rational& a, const Rational& b) {
	Rational b_reversed = Rational(b.Denominator(), b.Numerator());
	return a * b_reversed;
}

int main()
{
	{
		Rational a(2, 3);
		Rational b(4, 3);
		Rational c = a * b;
		bool equal = c == Rational(8, 9);
		if (!equal)
		{
			cout << "2/3 * 4/3 != 8/9" << endl;
			return 1;
		}
	}

	{
		Rational a(5, 4);
		Rational b(15, 8);
		Rational c = a / b;
		bool equal = c == Rational(2, 3);
		if (!equal)
		{
			cout << "5/4 / 15/8 != 2/3" << endl;
			return 2;
		}
	}
	cout << "OK" << endl;
	return 0;
}