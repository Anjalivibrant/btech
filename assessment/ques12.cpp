#include<iostream>
using namespace std;
const float limit=45.0;
int main(){
    float miles,speed;
    cout<<"Enter the speed of the vehicle(km/hr):"<<endl;
    cin>>speed;
    cout<<"Enter the miles travelled:"<<endl;
    cin>>miles;
    if(speed>limit){
        cout<<"The vehicle was speeding as the speed limit is "<<limit<<"km/hr."<<endl;
        cout<<"The fine per mile is $10."<<endl;
        cout<<"The fine to be payed is: $"<<10*miles<<endl;
    }
    else{
        cout<<"The vehicle was usnder the speed limit of "<<limit<<"km/hr."<<endl;
        cout<<"No fine needs to be payed."<<endl;
    }
    return 0;
}