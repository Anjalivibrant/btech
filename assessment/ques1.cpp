#include<iostream>
using namespace std;
float discount(float amt){
    float disAmt=(0.1)*amt;
    float totalAmt=amt-disAmt;
    return totalAmt;
}
int main()
{
    float amt,totalAmt,discountamt;
    cout<<"Please enter the Total amount of the shopping done in $:"<<endl;
    cin>>amt;
    if(amt>100){
     totalAmt=discount(amt);
    }
    else{
        totalAmt=amt;
    }
    cout<<"The total amount to be paid is: "<<totalAmt<<"$"<<endl;
    return 0;
}
/*

#include<iostream>
using namespace std;
string totalBill[100];//to store the total bill of the shopping
string sectionBill[100];//to store the sectionwise bill
int quan,amt,cost,totalAmt,sectionAmt,pointer1,pointer2;//global variables
void proBill(string pro,int q,int amt)
{
    sectionBill[pointer1++]=pro;
    sectionBill[pointer1++]=to_string(q);
    sectionBill[pointer1++]=to_string(amt);
}
void displaySection(){
  cout<< "\nChoices in Women's section:"<<endl;
  cout<< "\n 1.Ethnic Wear\n 2.Casual Wear\n 3.Formal Wear\n 4.Western Wear\n 5.Party Wear"<<endl;
  cout<<"We are extremely delighted to announce that we provide 15% discount in the Casual Wear and 25% discount in the Party Wear."<<endl;
}
int chooseSection(){
  int choice;
  cout<< "Select a choice by entering a number: "<<endl;
  cin>> choice;
  if(choice>=1&&choice<=5){
    return choice;}
  else {
    cout<<"\nPlease renter the choice as the previous choice entered was not correct."<<endl;
    displaySection();
    chooseSection();}
}
void displayProduct(int index){
  cout<< "\nAvailable Products are: "<<endl;
  string section[5][5]={{"Saree 2000/-","Patiyalas 500/-","Churidaars 400/-","Salwar Kameez 1000/-","Kurti 400/-"},
                    {"Pants 900/-","T-Shirt 400/-","Skirts 600/-","Sweaters 500/-","Dresses 900/-"},
                    {"Pants 700/-","Shirt 500/-","T-Shirt 400/-","Skirts 700/-","Coats 450/-"},
                    {"Denim Jeans 1300/-","Tops 500/-","Bell Bottom 700/-","A-Line Skirt 600/-","Denim Jacket 1100/-"},
                    {"Cocktail Dress 3500/-","Disco Dress 3000/-","A-Line Dress 1200/-","Pagent Dress 2300/-","Mini Dress 2200/-"}};
  for(int i=0;i<5;i++){
    cout<< i+1<<". "<<section[index][i]<<endl;
  }
}
string productReturn(int index1,int index2)
{
  string section[5][5]={{"Saree 2000/-","Patiyala 500/-","Churidaar 400/-","Salwar K 1000/-","Kurti 400/-"},
                    {"Pants 900/-","T-Shirt 400/-","Skirts 600/-","Sweaters 500/-","Dresses 900/-"},
                    {"Pants 700/-","Shirt 500/-","T-Shirt 400/-","Skirts 700/-","Coats 450/-"},
                    {"Denim Je. 1300/-","Tops 500/-","Bell B. 700/-","A-Line S. 600/-","Denim J. 1100/-"},
                    {"Cocktail 3500/-","Disco D 3000/-","A-Line D 1200/-","Pagent D 2300/-","Mini D 2200/-"}};
  return (section[index1][index2]);
}
int chooseProduct(){
  int choice;
  cout<<"\n Select a product using the number: "<<endl;
  cin>> choice;
  if(choice>=1&&choice<=5)
  {
    return choice;
  }
  else
  {
    cout<<"\nPlease renter the choice as the previous choice entered was not correct."<<endl;
    chooseProduct();
  }
}
string size()
{
   string s;
   cout<<"We provide sizes ranging from Small(S), Medium(M), Large(L) and Extra Large(XL)."<<endl;
   cout<<"Please Enter The Size you want using the characters."<<endl;
   cin>> s;
   return s;
}
int quantity()
{
  int q;
  cout<< "Enter the quantity of the chosen product: "<<endl;
  cin>> q;
  return q;
}
void line(){
  cout<<"----------------------------------------------"<<endl;
}
int price(int index1,int index2){
int amount[5][5]={{2000,500,400,1000,400},{900,400,600,500,900}, {700,500,400,700,450}, {1300,500,700,600,1100},{3500,3000,1200,2300,2200}};
return (amount[index1][index2]);
}
void process(int sec)
{
   displayProduct(sec-1);
   int pro=chooseProduct();
   quan=quantity();
   cost=price(sec-1,pro-1);
   amt=cost*quan;
   sectionAmt+=amt;   
   string apparel=productReturn(sec-1,pro-1);
   proBill(apparel,quan,amt);
}
void billPrint(int sec)
{
  int temp=1;
  cout<<"Product \t\t Quantity \t\t Amount"<<endl;
  for(int i=0;i<pointer1;i++){
    cout<<sectionBill[i]<<"\t\t      ";
    totalBill[pointer2++]=sectionBill[i];
    temp+=1;
    if(temp>3)
    {
      cout<<endl;
      temp=1;}} 
    cout<<"Total cost: "<<sectionAmt<<endl;
    if(sec==2 || sec==5){
      cout<<"Total cost without discount: "<<sectionAmt<<endl;
      float discount;
       if(sec==2){
        discount=(0.15)*sectionAmt;
        sectionAmt = sectionAmt-discount;
        cout<<"Total cost with discount of 15% is: "<<sectionAmt<<endl;}
       else{
         discount=(0.15)*sectionAmt;
         sectionAmt= sectionAmt -discount;
         cout<<"Total cost with discount of 25% is: "<<sectionAmt<<endl;}
     }
    totalAmt+=sectionAmt;//this is calculating the total bill
    cout<<"Current Total Bill: "<<totalAmt<<endl;
    line();//to distinguish between the sections
}
int main()
{
    cout<<"\nWelcome to Klassy!"<<endl;
    cout<<"Your one stop solution for shopping."<<endl;
    string name;//to input user's name
    cout<< "Enter Coustomer Name: "<< endl;
    getline(cin,name);//using the getline function to take input for more than one word
    cout<< "Hello "<< name <<"! What would you like to shop for today?"<<endl;
    cout<< "\nClothing store where all your needs for clothes are fulfilled."<<endl;
    cout<< "If you are in the mood of shopping then you're in the right place."<<endl;
    line();//calling the line function
    char ans;totalAmt=0;pointer2=0;
    do{
       cout<< "Welcome to the Women's section"<<endl;
       displaySection();
       int sec=chooseSection();
       string sizing;
       char choicing;
       switch(sec)
       {
        case 1:cout<<"WELCOME TO THE ETHINIC SECTION"<<endl;
               sizing=size();
               sectionAmt=0;pointer1=0;
               do{
               process(sec);               
               cout<<"Enter Y for yes if you want to continue shopping in the Ethnic Section"<<endl;
               cin >> choicing;
               }while(choicing=='y'||choicing=='Y');
               if(pointer1>0)              {
                   cout<<"Bill for the Ethnic Wear Section for size "<<sizing<<" :"<<endl;
                   billPrint(sec);              }
               break;
        case 2:cout<<"WELCOME TO THE CASUAL WEAR SECTION"<<endl;
               sizing=size();
               cout<<"Discount of 15% in this section."<<endl;
               sectionAmt=0;pointer1=0;
               do{
               process(sec);               
               cout<<"Enter Y for yes if you want to continue shopping in the Casual Section"<<endl;
               cin >> choicing;
               }while(choicing=='y'||choicing=='Y');
               if(pointer1>0)              {
                   cout<<"Bill for the Casual Wear Section for size "<<sizing<<" :"<<endl;
                   billPrint(sec);              }
               break;
        case 3:cout<<"WELCOME TO THE FORMAL WEAR SECTION"<<endl;
               sizing=size();
               sectionAmt=0;pointer1=0;
               do{
               process(sec);               
               cout<<"Enter Y for yes if you want to continue shopping in the Formal Section"<<endl;
               cin >> choicing;
               }while(choicing=='y'||choicing=='Y');
               if(pointer1>0)              {
                   cout<<"Bill for the Formal Wear Section for size "<<sizing<<" :"<<endl;
                   billPrint(sec);               }
               break;
        case 4:cout<<"WELCOME TO THE WESTERN WEAR SECTION"<<endl;
               sizing=size();
               sectionAmt=0;pointer1=0;
               do{
               process(sec);               
               cout<<"Enter Y for yes if you want to continue shopping in the Western Section"<<endl;
               cin >> choicing;
               }while(choicing=='y'||choicing=='Y');
               if(pointer1>0){
                   cout<<"Bill for the Western Wear Section for size "<<sizing<<" :"<<endl;
                   billPrint(sec);}
               break;
        case 5:cout<<"WELCOME TO THE PARTY WEAR SECTION"<<endl;
               sizing=size();
               cout<<"Discount of 25% in this section."<<endl;
               sectionAmt=0;pointer1=0;
               do{
               process(sec);               
               cout<<"Enter Y for yes if you want to continue shopping in the Party Section"<<endl;
               cin >> choicing;
               }while(choicing=='y'||choicing=='Y');
               if(pointer1>0){
                   cout<<"Bill for the Party Wear Section for size "<<sizing<<" :"<<endl;
                   billPrint(sec); }
               break;
       }
       cout<<"Enter Y for yes you want to continue shopping:"<<endl;
       cin>>ans;
    }while(ans=='Y'||ans=='y');
    cout<<"*************************"<<endl;
    cout<<"TOTAL BILL"<<endl;
    int temp=1;
    cout<<"Product \t\t Quantity \t\t Amount"<<endl;
    for(int i=0;i<pointer2;i++){
      cout<<totalBill[i]<<"\t\t\t";
      temp+=1;
      if(temp>3){
        cout<<endl;
        temp=1;}}
    cout<<"Total Money spent on shopping:(with discount) Rs."<<totalAmt<<endl;
    cout << "Thank you for shopping with us, " << name << "!" << endl;
  return 0;
}*/