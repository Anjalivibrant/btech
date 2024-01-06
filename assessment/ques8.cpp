#include<iostream>
using namespace std;
int main(){
    float miles;
    cout<<"Enter the miles travelled by the employee:"<<endl;
    cin>>miles;
    if(miles>100){
        cout<<"The reimburse amount per mile is $0.50."<<endl;
        cout<<"So the total amount reimbursed is: $"<<0.50*miles<<endl;
    }
    else{
        cout<<"The reimburse amount per mile is $0.40."<<endl;
        cout<<"So the total amount reimbursed is: $"<<0.40*miles<<endl;
    }
}