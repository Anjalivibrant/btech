#include<iostream>
#include<cmath>
using namespace std;
int main(){
    float height,weight,bmi;
    int age;
    cout<<"Please enter your height(in m):"<<endl;
    cin>>height;
    cout<<"Please enter your weight(in kg):"<<endl;
    cin>>weight;
    cout<<"Please enter your age:"<<endl;
    cin>>age;
    bmi=weight/(height*height);
    if(bmi>=18.5 && bmi<=25 && age<40){
        cout<<"The person's BMI: "<<bmi<<" falls under the normal healthy range."<<endl;
        cout<<"The person is in Good Fitness."<<endl;
    }
    else{
        cout<<"The person's BMI: "<<bmi<<" is out of the normal range."<<endl;
        cout<<"The person is not in Good Fitness."<<endl;
    }
    return 0;
}