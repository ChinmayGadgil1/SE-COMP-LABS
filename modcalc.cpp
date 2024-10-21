#include <iostream>
using namespace std;

int main()
{

    int n[10]={7515,4841,2682,4943,7314,8562,1836,5733,5957,6174};

    for(int i=0;i<10;i++)
    {
        cout<< n[i]<<" => ";
        cout << n[i] % 17 << "\n";
    }

    return 0;
}