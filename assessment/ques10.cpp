#include<iostream>
using namespace std;
int main(){
    cout<<"Welcome to Airport Security Check"<<endl;
    int age;
    cout<<"Please enter the age of the passenger:"<<endl;
    cin>>age;
    if(age<18){
        cout<<"There will be addition screening done for the passenger."<<endl;
    }
    else{
        cout<<"There will be normal screening done for the passenger."<<endl;
    }
    return 0;
}
