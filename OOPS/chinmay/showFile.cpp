# include<bits/stdc++.h>
using namespace std;



int main(){

ifstream f;
f.open("showFile.cpp");
char str[100];
while (f)
{
    cout<<(char)f.get()<<flush;
    _sleep(20);
}

f.close();

return 0;
}