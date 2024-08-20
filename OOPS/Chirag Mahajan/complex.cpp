#include<iostream>
using namespace std;

class Complex{
    int a, b;
    public:
    Complex(): a(0),b(0){}
    Complex(int real,int imag):a(real), b(imag){}
    Complex operator+(const Complex& other){
        return Complex(a+other.a, b+other.b);
    }
    Complex operator*(const Complex& other){
        int real=(a*other.a)-(b*other.b);
        int imag=(a*other.b)+(b*other.a);
        return Complex(real, imag);
    }
    Complex operator<<(const Complex& other){
        
    }
};
int main(){

return 0;
}