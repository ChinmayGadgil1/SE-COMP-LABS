# include<iostream>
# include<cmath>
using namespace std;




int main(){

    double a,b,ans;
    char c;
    cout.fill('*');
    cout.width(22);
    cout<<"\n";
    cout.fill(' ');
    cout<<"WELCOME TO CALCULATOR\n";
    cout.fill('*');
    cout.width(22);
    cout<<" ";
    cout.fill(' ');

    while (true)
    {
        cout<<"\nEnter expression: ";
        cin>>a>>c>>b;
        switch (c)
        {
        case '+':
            try
            {
                ans=a+b;
            }
            catch(...)
            {
                cerr <<"Some error occured"<< '\n';
                ans=INT16_MIN;
            }
            break;
        case '-':
            try
            {
                ans=a-b;
            }
            catch(...)
            {
                cerr <<"Some error occured"<< '\n';
                ans=INT16_MIN;
            }
            break;
        case '*':
            try
            {
                ans=a*b;
            }
            catch(...)
            {
                cerr <<"Some error occured"<< '\n';
                ans=INT16_MIN;
            }
            break;
        case '/':
            try
            {
                if(b==0){
                    ans=INT16_MIN;
                    throw "UNDEFINED";
                }
                ans=a/b;
            }
            catch(const char* e)
            {
                cerr <<e<< '\n';
            }
            break;
        
        default:
            break;
        }
        if (ans!=INT16_MIN)
        {
            cout<<ans<<endl;
        }
    }
    

return 0;
}