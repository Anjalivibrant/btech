#include<iostream>
using namespace std;
int main(){
    float balance;
    cout<<"Enter the outstanding balance:"<<endl;
    cin>>balance;
    if(balance>1000){
        cout<<"The Rate of Intrest is 15%."<<endl;
    }
    else{
        cout<<"The Rate of Intrest is 10%."<<endl;
    }
    return 0;
}