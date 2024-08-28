#include <iostream>
using namespace std;

class Grandparent{
    public:
    void showGrandparent(){
        cout<<"This is Grandparent class"<<endl;
    }
};

class Father : public Grandparent{
    public:
    void showFather(){
        cout<<"This is Father class"<<endl;
    }
};

class Child : public Father{
    public:
    void showChild(){
        cout<<"This is Child class"<<endl;
    }
};

int main(){
    Child c;
    c.showGrandparent();
    c.showFather();
    c.showChild();
    return 0;
}