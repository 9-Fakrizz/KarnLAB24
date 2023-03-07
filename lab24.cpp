#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		ComplexNumber operator+(const ComplexNumber &);
		ComplexNumber operator-(const ComplexNumber &);
		ComplexNumber operator*(const ComplexNumber &);
		ComplexNumber operator/(const ComplexNumber &);
		bool operator==(const ComplexNumber &);
		double abs();
		double angle();
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real+c.real,imag+c.imag);
}
ComplexNumber operator+(double a,const ComplexNumber &c){
	return ComplexNumber(c.real + a,c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real-c.real,imag-c.imag);
}
ComplexNumber operator-(double a,const ComplexNumber &c){
	return ComplexNumber(a - c.real,c.imag);
}

//my code
ComplexNumber ComplexNumber::operator*(const ComplexNumber &c){
	double a,b;
	a = (real*c.real)-(imag*c.imag);
	b = (real*c.imag)+(imag*c.real);
	return ComplexNumber(a,b);
}
ComplexNumber operator*(double g,const ComplexNumber &c){
	double a,b;
	a = (g*c.real);
	b = (g*c.imag);
	return ComplexNumber(a,b);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c){
	double a,b;
	// c = pow(c.real,2)+pow(c.imag,2);
	a = (real*c.real)+(imag*c.imag);
	b = (imag*c.real)-(real*c.imag);
	return ComplexNumber(a/pow(c.real,2)+pow(c.imag,2),b/pow(c.real,2)+pow(c.imag,2));
}
ComplexNumber operator/(double g,const ComplexNumber &c){
	double a,b;
	// c = pow(c.real,2)+pow(c.imag,2);
	a = (g*c.real);
	b = -(g*c.imag);
	return ComplexNumber(a/pow(c.real,2)+pow(c.imag,2),b/pow(c.real,2)+pow(c.imag,2));
}

bool ComplexNumber::operator==(const ComplexNumber &c){
	if(c.real == real && c.imag == imag){
		return true;
	}
	else{
		return false;
	}
}

bool operator==(double a,const ComplexNumber &c){
	if(c.real == a){
		return true;
	}
	else{
		return false;
	}
}

double ComplexNumber::abs(){
	return (pow(pow(real,2)+pow(imag,2),0.5));
}
double ComplexNumber::angle(){
	return (atan2 (imag,real) * 180 / M_PI) ;
}
ostream & operator<<(ostream &os, const ComplexNumber &c){
	if(c.real==0 && c.imag ==0) return os << "0";
	else if(c.real==0) return os << c.imag << "i";
	else if(c.imag == 0) return os << c.real;
	else if(c.imag < 0) return os << c.real << c.imag << "i";
	else return os << c.real << "+" << c.imag<<"i";
}


int main(){
	ComplexNumber a(1.5,2),b(3.2,-2.5),c(-1,1.2);	
	cout << a << "\n";
	cout << b << "\n";
	cout << c << "\n";
	cout << a+2.5 << "\n";
	cout << 2.5+a << "\n";
	cout << a-1.5 << "\n";
	cout << 1.5-a << "\n";
	cout << b+ComplexNumber(0,2.5) << "\n";
	cout << c-c << "\n";
	cout << "-----------------------------------\n";
	
	ComplexNumber d = (a+b)/c;
	ComplexNumber e = b/(a-c);
	cout << d << "\n";
	cout << e << "\n";
	cout << c*2 << "\n";
	cout << 0.5*c << "\n";
	cout << 1/c << "\n";
	cout << "-----------------------------------\n";
	
	cout << ComplexNumber(1,1).abs() << "\n";
	cout << ComplexNumber(-1,1).abs() << "\n";
	cout << ComplexNumber(1.5,2.4).abs() << "\n";
	cout << ComplexNumber(3,4).abs() << "\n";
	cout << ComplexNumber(69,-9).abs() << "\n";		
	cout << "-----------------------------------\n";	
	
	cout << ComplexNumber(1,1).angle() << "\n";
	cout << ComplexNumber(-1,1).angle() << "\n";
	cout << ComplexNumber(-1,-1).angle() << "\n";
	cout << ComplexNumber(1,-1).angle() << "\n";
	cout << ComplexNumber(5,2).angle() << "\n";
	cout << "-----------------------------------\n";
	
	cout << (ComplexNumber(1,1) == ComplexNumber(1,2)) << "\n";
	cout << (ComplexNumber(1,1) == 1) << "\n";
	cout << (0 == ComplexNumber()) << "\n";
}





