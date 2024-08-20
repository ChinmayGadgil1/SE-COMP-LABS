#include<iostream>
#include<deque>
using namespace std;
#define MAX 4;

int front=-1, rear=-1;
int queuearr[MAX];

int isFull(){
    return rear=MAX-1;
}

int isEmpty(){
    return front==-1 || front>rear;;
}

class String{
    private:
    string value;

    public: 
    String(const string& val) : value(val){
        cout<<"String object created with value: "<<value <<endl;
    }
    
    ~String(){
        cout<<"String object with value "<<value<<" has been destroyed"<<endl;

    }

    void display() const{
            cout<<value<<endl;
        }

};

int main(){

    string str1("Hello");
    string str2("World");

    str1.display();
    str2.display();

    return 0;
}

void getLeft(){
    
}