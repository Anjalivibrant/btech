#include<iostream>
using namespace std;
int main(){
    int age;float num;
    cout<<"Enter the number of years for this health insurance."<<endl;
    cin>>num;
    cout<<"Enter the age of the Policy Holder:"<<endl;
    cin>>age;
    if(age<30){
        cout<<"The Health Insurance Premium is 200$."<<endl;
        cout<<"The Total Insurance for "<<num<<" years= "<<num*200<<"$"<<endl;
    }
    else{
        cout<<"The Health Insurance Premium is 300$."<<endl;
        cout<<"The Total Insurance for "<<num<<" years= "<<num*300<<"$"<<endl;
    }
}