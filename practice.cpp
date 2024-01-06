#include<iostream>
using namespace std;
int main(){
    //concatenation of string arrays
    string data[10];
    int index=0;
    string name[10]={"abc","def","ghi","jkl","mno","pqr","stu","vwx","yza","wed"};
    string marks[10]={"12","23","34","45","56","67","78","89","90","01"};
    for(int i=0;i<10;i++){
        data[i]=(name[i]+"\t\t|"+marks[i]+" |");
    }
    for(int i=0;i<10;i++){
        cout<<data[i]<<endl;
    }
    int del,size=10;
    cout<<"Enter element to delete:"<<endl;
    cin>> del;
    //deleting the data from array
     for(int i=del;i<size-1;i++){
          data[i]=data[i+1];
       }
     for(int i=0;i<9;i++){
        cout<<data[i]<<endl;
    }  
    //SEARCHING A STRING ARRAY ELEMENT USING THE NAME/DATA
    /*string nameArray[5];
    int index=0;
    for(int i=0;i<5;i++){
        cout<<"Enter name "<<(i+1)<<" :"<<endl;
        cin>>nameArray[i];
    }
    string searchName;
    cout<<"Enter name to be searched:"<<endl;
    cin>> searchName;
    for(int i=0;i<5;i++){
        index++;
        if(nameArray[i] == searchName){
            cout<<"Name found at "<<i+1<<" position."<<endl;
            break;
        }
    }
    if(index==0){
        cout<<"Name not found"<<endl;
    }*/
}