#include<iostream>
using namespace std;
string name[20];
int index1=0,index2=0,index3=0;
int grade[100];
string saveDataArray[150];
int (){
    int choice;
    cout<<"Enter your choice using number:"<<endl;
    cout<<"1. Add student name"<<endl;
    cout<<"2. View student grade"<<endl;
    cout<<"3. Average grade of each student"<<endl;
    cout<<"4. Delete student data"<<endl;
    cout<<"5. Exit"<<endl;
    cin>> choice;
    if(choice<1 || choice>5){
        cout<<"Invalid input! Please enter your choice correctly."<<endl;
        list();
    }
    else{
        return choice;
    }
}
void data(int i,int j){
    saveDataArray[index3++]=(name[i]+"\t\t|"+to_string(grade[j])+"\t"+to_string(grade[j+1]) +"\t"+to_string(grade[j+2]) +"\t"+to_string(grade[j+3]) +"\t"+to_string(grade[j+4])+" |");
}
void student_grade(){
    for(int i=0;i<5;i++){
        cout<<"Enter marks of Subject "<<i+1<<endl;
        cin>>grade[index2++];
        // if(grade[index2]>100 || grade[index2]<0){
        //     cout<<"Invalid input! Re-enter the grade of Subject "<<i+1<<endl;
        //     cin>>grade[index2];
        // }
    }
}
void print_data(){
    int pointer=1;
    cout<<endl<<"Student Data: "<<endl;
    /*for(int i=0;i<index3;i++){
       cout<< saveDataArray[i]<<"\t\t";
       pointer+=1;
       if(pointer>6)
       {
        cout <<endl;
        pointer=1;
       }
    }*/
    for(int i=0;i<index3;i++){
        cout<<saveDataArray[i]<<endl;
    }
}
void student_name(){
    cout<<"Enter Student Name: "<<endl;
    cin>>name[index1++];
    student_grade();
    data(index1-1,index2-5);
   // print_data();
}
/*Returning the index of the name*/
int return_index(string word){
    int pointer=-1;
    for(int i=0;i<index1;i++){
        if(word == name[i]){
            pointer=i;
            break;
        }
    }
    cout<<"Word is at "<<pointer<<" position."<<endl;
    return pointer;
}
void del_data(){
    string changes;
    cout<<"Enter the name of student you want to remove: "<<endl;
    cin>> changes;
    int pointer=return_index(changes);
    if(pointer == -1){
        cout<<"Name not found! Re-enter the name: "<<endl;
        del_data();
    }
    else{
       //deleting from the saveDataArray
    for(int i=pointer;i<(index3-1);i++){
        saveDataArray[i]=saveDataArray[i+1];
    }
    index3--;
    }
}
void process(){
    int choice=list();
    switch (choice)
 {
    case 1://Adding student name
    student_name();
    break;
    case 2://view grade
    print_data();
    break;
    case 3:
    break;
    case 4://delete student data
    del_data();
    break;
    case 5:
    break;
    default:
    break;
 }
 if(choice!=5){
    process();
 }
}
int main()
{
    process();
 return 0;
}