#include "rational.h"

int rational::gcd(int a, int b){ // calculates gcd Note: gcd will always be positive
    if (a < 0){
        a = -a;
    }
    if (b < 0){
        b = -b;
    }
    int t;
    while (b != 0){
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int rational::lcm(int a, int b){
    if (a < 0){
        a = -a;
    }
    if (b < 0){
        b = -b;
    }
    return (a * b) / gcd(a, b);

}

rational::rational(){
    this->n = 0;
    this->d = 1;
}

rational::rational(int q){
    this->n = q;
    this->d = 1;
}

rational::rational(int n, int d){
    int gcdvalue = gcd(n, d);

	this->n = n / gcdvalue;
	this->d = d / gcdvalue;
	if (d < 0){
        this->n = -this->n;
        this->d = -this->d;
	}

}

rational rational::operator+(const rational &r) const {
	int t = lcm(d, r.d);
	rational brandNew;
/*  int n1 = n;
	int d1 = d;

	int q1 = this->n * (t / this->d);
	int q2 = r.n * (t / r.d);
	int q3 = q1 + q2;*/
	brandNew.n = (this->n * (t / this->d) + r.n * (t / r.d));
	brandNew.d = t;
	return brandNew;
}

rational rational::operator-(const rational &r) const {
    int t = lcm(d, r.d);
	rational brandNew;
	brandNew.n = (this->n * (t / this->d) - r.n * (t / r.d));
	brandNew.d = t;
	return brandNew;
}

rational rational::operator*(const rational &r) const {
    rational brandNew;
    brandNew.n = this->n * r.n;
    brandNew.d = this->d * r.d;
    return brandNew;
}

rational rational::operator/(const rational &r) const {
    rational brandNew;
    brandNew.n = this->n * r.d;
    brandNew.d = this->d * r.n;
    return brandNew;
}

int rational::getNum() const{
	return this->n;
}

int rational::getDenom() const{
	return this->d;
}
