#include <iostream>
#include <algorithm>

using namespace std;

// Реализуйте для класса Rational операторы ==, + и -

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

Rational operator+ (const Rational& a, const Rational&b) {
	int a_num = a.Numerator();
	int b_num = b.Numerator();
	int a_den = a.Denominator();
	int b_den = b.Denominator();
	int res_den = a_den / gcd(a_den, b_den) * b_den;
	int res_num = a_num * (res_den / a_den) + b_num * (res_den / b_den);
	return Rational(res_num, res_den);
}

Rational operator- (const Rational& a, const Rational&b) {
	Rational b_negative = Rational(-b.Numerator(), b.Denominator());
	return a + b_negative;
}

int main()
{
	{
		Rational r1(4, 6);
		Rational r2(2, 3);
		bool equal = r1 == r2;
		if (!equal)
		{
			cout << "4/6 != 2/3" << endl;
			return 1;
		}
	}

	{
		Rational a(2, 3);
		Rational b(4, 3);
		Rational c = a + b;
		bool equal = c == Rational(2, 1);
		if (!equal)
		{
			cout << "2/3 + 4/3 != 2" << endl;
			return 2;
		}
	}

	{
		Rational a(5, 7);
		Rational b(2, 9);
		Rational c = a - b;
		bool equal = c == Rational(31, 63);
		if (!equal)
		{
			cout << "5/7 - 2/9 != 31/63" << endl;
			return 3;
		}
	}
	cout << "OK" << endl;
	return 0;
}