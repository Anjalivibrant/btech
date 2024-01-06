#include<iostream>
using namespace std;
int main(){
    float temp;
    cout<<"Please enter the temperature in celcius:"<<endl;
    cin>>temp;
    cout<<"The Activity suited to you:"<<endl;
    if(temp<=15&&temp>=-10){
     cout<<"Please rember to wear layers and keep on the heat at your place."<<endl;
    }
    else if(temp>=16&&temp<=30){
     cout<<"It looks like you have good weather today and can probably indulge in your hobbies.\n Be on the lookout for beautiful flowers and vegitation when outdoors.  "<<endl;
    }
    else if(temp>=31&&temp<=47){
     cout<<"It seems that you have hot temperature and so remember to stay hydrated."<<endl;
    }
    else{
        cout<<"Sorry to tell you but the only activity left for you is to pray to the lord!\nWe wish you all the best for your future endevours."<<endl;
    }
    return 0;
}