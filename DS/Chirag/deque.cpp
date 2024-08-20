#include<iostream>
#include<deque>
using namespace std;

// class deque{
//     int size;
//     int front,back;
//     string* arr;
//     public:
//         void push_front();
// }


int main(){

string Name1="BKL1";
string Name2="BKL2";
string Name3="BKL3";
string Name4="BKL4";
string Name5="BKL5";
string Name6="BKL6";
string Name7="BKL7";
string Name8="BKL8";

deque<string> dq;
dq.push_front(Name1);
dq.push_front(Name2);
dq.push_front(Name3);
dq.push_front(Name4);
dq.push_back(Name5);
dq.push_back(Name6);
dq.push_back(Name7);
dq.push_back(Name8);




return 0;
}