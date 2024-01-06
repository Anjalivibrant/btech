#include<iostream>
using namespace std;
int main(){
    int choice;
    cout<<"1.Online Gaming\n2.Video Streaming\n3.Live Server Networking\n4.E-Book Reading\n5.Scrolling through Social Media"<<endl;
    cout<<"Please Enter the activity choice using the number."<<endl;
    cin>>choice;
    if(choice>=1&&choice<=3){
        cout<<"The User need High Speed Plan based on their activity."<<endl;
    }
    else if(choice>=4&&choice<=5){
        cout<<"The user needs Normal Speed plan based on their activity."<<endl;
    }
    else{
        cout<<"Invaild Input!"<<endl;
    }
    return 0;
}