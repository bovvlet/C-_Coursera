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
		if (denominator == 0)
			throw invalid_argument("Invalid argument");
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

Rational operator* (const Rational& a, const Rational& b) {
	return Rational(a.Numerator() * b.Numerator(), 
					a.Denominator() * b.Denominator());
}

Rational operator/ (const Rational& a, const Rational& b) {
	if (b.Numerator() == 0){
        throw domain_error("Division by zero");
    }
    Rational b_reversed = Rational(b.Denominator(), b.Numerator());
	return a * b_reversed;
}

istream& operator>> (istream& stream, Rational& rational) {
	if (char(stream.peek()) != -1) {
		int numerator, denominator;
		stream >> numerator;
		stream.ignore(1);
		stream >> denominator;
		rational = Rational(numerator, denominator);
	}
	return stream;
}

ostream& operator<< (ostream& stream, const Rational& rational) {
	stream << rational.Numerator();
	stream << '/';
	stream << rational.Denominator();
	return stream;
}

int main() {
    char op;
    Rational a, b;
    try {
        cin >> a >> op >> b;
        if (op == '+')
            cout << a + b;
        if (op == '-')
            cout << a - b;
        if (op == '*')
            cout << a * b;
        if (op == '/')
            cout << a / b;
    } catch (exception& ex) {
        cout << ex.what() << endl;
    }
}