#include<iostream>
using namespace std;

struct user{
string first_name;
string middle_name;
string last_name;
int units;
int charge;
};

void displayCharges(struct user u[],int s){
	float un;

	cout<<endl<<"Displaying calculated charges for "<<s<<" users..."<<endl;
	for(int i=0;i<s;i++){
		un=u[i].units;
		if(un<100){
			u[i].charge=u[i].units*60;
			}
		else if(un<300){
			u[i].charge=(un-100)*80+6000;
		}
		else if(un>300){
			u[i].charge=(un-300)*90+6000+16000;
		}
		
		cout<<endl;
		cout<<"Name: "<<u[i].first_name<<" "<<u[i].middle_name<<" "<<u[i].last_name<<endl;
		cout<<"Units consumed: "<<u[i].units<<endl;
		cout<<"Charge: "<<u[i].charge<<endl;	
	}


}

int main(){

	int s;
	cout<<"Enter number of users: ";
	cin>>s;
	
	struct user u[s];
	
	for(int i=0;i<s;i++){
	cout<<endl<<"Enter details of user "<<i+1<<":"<<endl;
	cout<<"Enter full name: ";
	cin>>u[i].first_name>>u[i].middle_name>>u[i].last_name;
	cout<<"Enter number of units consumed: ";
	cin>>u[i].units;
	
	}
	
	displayCharges(u,s);

return 0;
}
