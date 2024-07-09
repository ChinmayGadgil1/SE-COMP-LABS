#include<iostream>
using namespace std;

struct user{
string name;
int units;
float charge;
};

void displayCharges(struct user u[],int s){
	float un;
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
		cout<<"Name: "<<u[i].name<<endl;
		cout<<"Charge: "<<u[i].charge<<endl;	
	}


}

int main(){

	int s;
	cout<<"Enter number of users: ";
	cin>>s;
	
	struct user u[s];
	
	for(int i=0;i<s;i++){
	
	cout<<"Enter name and units consumed for user "<<i+1<<":"<<endl;
	cin>>u[i].name>>u[i].units;
	
	}
	
	displayCharges(u,s);

return 0;
}
