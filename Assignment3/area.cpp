#include<iostream>
using namespace std;
float areaOfShape;
void circle(){
    float radius;
    cout<<"Enter the radius: "<<endl;
    cin>> radius;
    areaOfShape=(3.14)*(radius*radius);
    cout<<"Area of the Circle: "<<areaOfShape<<endl;
}
void rectangle(){
    float length,width;
    cout<<"Enter the length: "<<endl;
    cin>>length;
    cout<<"Enter the width: "<<endl;
    cin>>width;
    areaOfShape=length*width;
    cout<<"Area of the Rectangle: "<<areaOfShape<<endl;
}
void triangle(){
    float height,base;
    cout<<"Enter the height: "<<endl;
    cin>>height;
    cout<<"Enter the base: "<<endl;
    cin>>base;
    areaOfShape=(0.5*(base*height));
    cout<<"Area of the Triangle: "<<areaOfShape<<endl;
}
int main(){
    int choice;
    cout<<"1. Area of a Circle"<<endl;
    cout<<"2. Area of a Rectangle"<<endl;
    cout<<"3. Area of a Triangle"<<endl;
    cout<<"Enter your choice: "<<endl;
    cin>>choice;
    switch(choice)
    {
        case 1:circle();
        break;
        case 2:rectangle();
        break;
        case 3:triangle();
        break;
        default:cout<<"Invalid Input!"<<endl;
    }
    return 0;
}