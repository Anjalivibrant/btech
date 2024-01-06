#include<iostream>
using namespace std;
int main(){
    float gpa;
    cout<<"Please enter the GPA:"<<endl;
    cin>>gpa;
    if(gpa>3.5){
        cout<<"Congratulations! You are eligible for a scholarship."<<endl;
    }
    else{
        cout<<"Sorry, you are not eligible for a scholarship."<<endl;
    }
    return 0;
}