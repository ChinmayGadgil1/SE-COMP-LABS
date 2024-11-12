# include<iostream>
using namespace std;

void f1(int i){
    if(1)
    throw(1);
    else
    throw(0);
}

void f1(char* str){
    try
    {
        if(str)
            throw("OK");
            else
            throw("NOT OK");
    }
    catch(const char* err)
    {
        cout<<err;
    }
    
}

int main(){

try
{

    f1(nullptr);
}
catch(int x)
{
    cout<<x << '\n';
}
catch(char* ptr){
    cout<<ptr;
}



return 0;
}