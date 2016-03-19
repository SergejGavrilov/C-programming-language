
#include "rational.h"

int rational::gcd(int a, int b) const { // calculates gcd Note: gcd will always be positive
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

int rational::lcm(int a, int b) const {
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
	rational brandNew;
	brandNew.n = (this->n * r.d + r.n * this->d);
	brandNew.d = r.d * this->d;
	int t = gcd(brandNew.n, brandNew.d);
	brandNew.n /= t;
	brandNew.d /= t;
	return brandNew;
}

rational rational::operator-(void) const{
	return rational(-this->n, this->d);
	
}

rational rational::operator-(const rational &r) const {
    return *this + (-r);
}

rational rational::operator*(const rational &r) const {
    rational brandNew;
    brandNew.n = this->n * r.n;
    brandNew.d = this->d * r.d;
	int t = gcd(brandNew.n, brandNew.d);
	brandNew.n /= t;
	brandNew.d /= t;
    return brandNew;
}

rational rational::operator/(const rational &r) const {
    rational brandNew;
    brandNew.n = this->n * r.d;
    brandNew.d = this->d * r.n;
	int t = gcd(brandNew.n, brandNew.d);
	brandNew.n /= t;
	brandNew.d /= t;
    return brandNew;
}

int rational::getNum() const{
	return this->n;
}

int rational::getDenom() const{
	return this->d;
}
