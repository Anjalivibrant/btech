#include<iostream>
#include<fstream>
using namespace std;
double amt=50000.00;
double with[30];
double dep[30];
const long pin= 123456;
long input;
int index1=0,index2=0,index3=0,sNo=1;
string sheet[30];
int options(){
    int choice;
    cout<<"1. CHECK YOUR BALANCE"<<endl;
    cout<<"2. DEPOSIT"<<endl;
    cout<<"3. WITHDRAWL"<<endl;
    cout<<"4. BALANCE SHEET"<<endl;
    cout<<"5. SAVE DETAILS"<<endl;
    cout<<"6.EXIT"<<endl;
    cout<<"Enter your choice:"<<endl;
    cin>>choice;
    return choice;
}
void balance(){
    cout<<endl<<"BALANCE IN ACCOUNT\t|"<<amt<<" |"<<endl;
}
void deposit(){
    double depAMT;
    cout<<endl<<"AMOUNT TO BE DEPOSITED IN AN ACCOUNT :"<<endl;
    cin>>depAMT;
    dep[index2++]=depAMT;
    amt+=depAMT;
}
void withdraw(){
    double withdrawAmt;
    cout<<endl<<"AMOUNT TO BE WITHDRAWN FROM ACCOUNT :"<<endl;
    cin>>withdrawAmt;
    if(withdrawAmt>amt){
        cout<<"AMOUNT IS OUT OF LIMIT OF THE BALANCE OF Rs."<<amt<<endl;
        cout<<"TRANSACTION FAILED!"<<endl;
    }
    else{
        with[index1++]=withdrawAmt;
        amt-=withdrawAmt;
    }
}
void balanceSheet(int check){// SN NO. BALANCE     DEPOSIT         WITHDRAW
if(check==1){
     sheet[index3++]=" "+to_string(sNo)+"\t|"+to_string(amt)+"\t|"+to_string(dep[index2])+"\t|  "+to_string(with[index1])+"\t";
}
else if(check==2){
     sheet[index3++]=" "+to_string(sNo)+"\t|"+to_string(amt)+"\t|"+to_string(dep[index2-1])+"\t|  "+to_string(with[index1])+"\t";
}
else{
     sheet[index3++]=" "+to_string(sNo)+"\t|"+to_string(amt)+"\t|"+to_string(dep[index2])+"\t|  "+to_string(with[index1-1])+"\t";
}
    sNo++;
}
void printBalSheet(){
    cout<<"The Balance Sheet for Acc. No- 41A56 :"<<endl;
    cout<<"SL NO.  |\tBALANCE |\tDEPOSIT |\tWITHDRAWL"<<endl;
    for(int i=0;i<index3;i++){
        cout<<sheet[i]<<endl;
    }
}
void saving(){
    ofstream outputFile;
outputFile.open("Balance.txt");
if(outputFile.is_open()){
    for(int i=0;i<index3;i++){
        outputFile<<sheet[i]<<endl;
    }
    cout<<"Data Saved Sucessfully in 'Balance.txt' File."<<endl;
}
else{
    cout<<"File could not be opened."<<endl;
}
outputFile.close();
}
void process(){
    int choice=options();
    switch (choice)
    {
        case 1: //check your balance
        balance();
        //balanceSheet(1);
        break;
        case 2: //deposit
        deposit();
        balanceSheet(2);
        break;
        case 3://withdraw
        withdraw();
        balanceSheet(3);
        break;
        case 4://balance sheet
        printBalSheet();
        break;
        case 5://save details
        saving();
        case 6:
        exit(0);
        default:
        cout<<"Invalid Input!"<<endl;
    }
    if(choice!=6){
        process();
    }
}
int main(){
    cout<<"Enter the 6-digit PIN: "<<endl;
    cin>>input;
    if(input==pin){
      process();
    }
   else{
    cout<<"Incorrect PIN!"<<endl;
   }
    return 0;
}