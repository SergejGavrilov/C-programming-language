#ifndef RATIONAL_H
#define RATIONAL_H


class rational{
	private:
		int n, d;
		int gcd(int a, int b) const;
        int lcm(int a, int b) const;

	public:
	    rational();
		rational(int);
		rational(int, int);
		int getNum() const;
		int getDenom() const;
		rational operator+(rational const &)const;
		rational operator-(rational const &)const;
		rational operator*(rational const &)const;
		rational operator/(rational const &)const;
		rational operator-(void)const;

};

#endif
