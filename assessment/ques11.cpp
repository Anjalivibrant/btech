#include<iostream>
using namespace std;
int main(){
    int choice;
    cout<<"Please enter your dietary preferance-\n1.Vegetarian\n2.Vegan\n3.Eggetarian\n4.Non-Vegetarian"<<endl;
    cin>>choice;
    switch (choice)
    {
    case 1:cout<<"According to your preferrance the meal provided will be- Masala Dosa."<<endl;
        break;
    case 2:cout<<"According to your preferrance the meal provided will be- Vegan Sakshuka with Bread."<<endl;
      break;
    case 3:cout<<"According to your preferrance the meal provided will be- Sakshuka with Bread."<<endl;
       break;
    case 4:cout<<"According to your preferrance the meal provided will be- Chicken Alfredo."<<endl;
    break;
    default:cout<<"Invalid Option!"<<endl;
        break;
    }
    return 0;
}