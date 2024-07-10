# include<iostream>
#include<math.h>
using namespace std;

bool isPrime(int n){
    bool checker=true;
    if (n<2)
    {
        return false;
    }
    
    if (n==2)
    {
        return checker;
    }
    
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n%i==0)
        {
            checker=false;
            break;
        }
        
    } 
    return checker;
}

bool isOdd(int n){
    return n%2!=0;
}

int main(){

cout<<"Enter a number: ";
int n;
cin>>n;


if (isOdd(n) && isPrime(n))     
{
    cout<<"The entered number is odd and also prime"<<endl;
}
else if (isOdd(n))
{
    cout<<"The entered number is odd but not prime"<<endl;
}
else if (isPrime(n))
{
    cout<<"The entered number is prime but not odd"<<endl;
}
else
{
    cout<<"The entered number is neither odd nor prime"<<endl;
}



return 0;
}