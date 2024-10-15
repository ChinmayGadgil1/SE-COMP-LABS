# include<bits/stdc++.h>
using namespace std;

int num=1;

class Todo{
    string text;
    bool isCompleted;
    public:
        Todo(){
            text="";
            isCompleted=false;
        }
        Todo(string t,bool c=false){
            text=t;
            isCompleted=c;
        }

        void create(){
            cout<<"\nEnter todo: ";
            cin.ignore();
            getline(cin,text);
        }

        void writeToFile(){
            fstream out;
            out.open("expt8.txt",ios::app);
            out<<num++<<") "<<text<<"\n";
            if(isCompleted){
                out<<"Completed✅\n\n";
            }
            else{
                out<<"Not Completed❌\n\n";
            }
            
        }
        friend void deleteTodo(int n);
    
};

void deleteTodo(int n){
    fstream out;
    out.open("expt8.txt",ios::app);
    out.seekg(ios::beg);
    while(!out.eof()){
        
    }   
}


int main(){

int choice;
while (true)
{
    cout<<"\nMenu:\n";
    cout<<"1)Enter todo\n2)Delete todo\n3)Edit todo\n";
    cout<<"Your choice: ";
    cin>>choice;

    if(choice==1){
        Todo t;
        t.create();
        t.writeToFile();
    }
    else if (choice==2)
    {
        int n;
        cout<<"Enter no of todo to delete:";
        cin>>n;
        deleteTodo(n);
    }
    
}



return 0;
}