#include <iostream>
#include <sstream>
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

int main()
{
	{
		ostringstream output;
		output << Rational(-6, 8);
		if (output.str() != "-3/4")
		{
			cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
			return 1;
		}
	}

	{
		istringstream input("5/7");
		Rational r;
		input >> r;
		bool equal = r == Rational(5, 7);
		if (!equal)
		{
			cout << "5/7 is incorrectly read as " << r << endl;
			return 2;
		}
	}

	{
		istringstream input("5/7 10/8");
		Rational r1, r2;
		input >> r1 >> r2;
		bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
		if (!correct)
		{
			cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
			return 3;
		}

		input >> r1;
		input >> r2;
		correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
		if (!correct)
		{
			cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
			return 4;
		}
	}
	cout << "OK" << endl;
	return 0;
}