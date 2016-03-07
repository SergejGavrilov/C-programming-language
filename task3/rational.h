#ifndef RATIONAL_H
#define RATIONAL_H


class rational{
	private:
		int n, d;
		int gcd(int a, int b);
        int lcm(int a, int b);

	public:
	    rational();
		rational(int q);
		rational(int n, int d);
		int getNum() const;
		int getDenom() const;
		rational operator+(rational);
		rational operator-(rational);
		rational operator*(rational);
		rational operator/(rational);

};

#endif
