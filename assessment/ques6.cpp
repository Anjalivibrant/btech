#include<iostream>
using namespace std;
int main(){
    int num;
    cout<<"Enter the number of books purchased:"<<endl;
    cin>>num;
    float price[num];
    float sum=0,discount;
    cout<<"Enter the price of all the books:"<<endl;
     for(int i=0;i<num;i++){
        cin>>price[i];
        sum+=price[i];
     }
    if(num>=1&&num<=2){
        cout<<"There is no discount for less than 3 books."<<endl;
        cout<<"The total of the books= "<<sum<<"$"<<endl;
    }
    else if(num>=3&&num<=5){
        cout<<"There is a discount of 5%."<<endl;
        cout<<"Amount before discount="<<sum<<"$"<<endl;
        discount=0.05*sum;
        cout<<"The total of the books= "<<sum-discount<<"$"<<endl;
    }
    else {
        cout<<"There is a discount of 10%."<<endl;
        cout<<"Amount before discount="<<sum<<"$"<<endl;
        discount=0.1*sum;
        cout<<"The total of the books= "<<sum-discount<<"$"<<endl;
    }
    return 0;
}