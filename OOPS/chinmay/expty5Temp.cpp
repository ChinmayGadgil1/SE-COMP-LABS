#include <iostream>
using namespace std;

class GrandParent
{
protected:
    string profession;
    long long phone_num;
public:
    GrandParent(string prof, long long ph)
    {
        profession = prof;
        phone_num = ph;
    }
    ~GrandParent() {}
};
class Parent : public GrandParent
{
protected:
    string facebook_id;

public:
    Parent(string prof, long long ph, string fa) : GrandParent(prof, ph)
    {
        facebook_id = fa;
    }
    ~Parent() {}
};
class Child : public Parent
{
protected:
    string insta_id;

public:
    Child(string prof, long long ph, string fa, string in) : Parent(prof, ph, fa)
    {
        insta_id = in;
    }
    void display()
    {
        cout << "\nProfession: " << profession;
        cout << "\nPhone num : " << phone_num;
        cout << "\nFacebook Id : " << facebook_id;
        cout << "\nInstagram Id : " << insta_id;
    }
    ~Child() {}
};
int main()
{
    string prof, fa, in;
    long long ph;
    cout << "Enter profession: ";
    getline(cin, prof);
    cout << "Enter phone number: ";
    cin >> ph;
    cout << "Enter Facebook Id: ";
    cin.ignore();
    getline(cin, fa);
    cout << "Enter Instagram Id: ";
    cin.ignore();
    getline(cin, in);
    Child c(prof, ph, fa, in);
    c.display();
    return 0;
}