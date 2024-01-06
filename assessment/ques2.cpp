#include<iostream>
using namespace std;
void weekday(int num){
    cout<<"Price of each ticket is 12$."<<endl;
    cout<<"Total price of all the tickets ="<<num*12<<"$"<<endl;
}
void weekend(int num){
     cout<<"Price of each ticket is 15$."<<endl;
    cout<<"Total price of all the tickets ="<<num*15<<"$"<<endl;
}
int main(){
    int number;
    cout<<"Enter the number of tickets you want:"<<endl;
    cin>>number;
    int day;
    cout<<"1.Monday\n2.Tuesday\n3.Wednesday\n4.Thursday\n5.Friday\n6.Saturday\n7.Sunday"<<endl;
    cout<<"Please enter the day(1-7) you want to watch the movie"<<endl;
    cin>>day;
    if(day>=1&&day<=5){
       weekday(number);
    }
    else if(day==6||day==7){
      weekend(number);
    }
    else{
        cout<<"Invalid input of day"<<endl;
    }
    return 0;
}