#include<iostream>
using namespace std;
int index=0,index2=5,index3=5;
class books{
 public:
 string book_name[50];
 string name[5]={"Twinkle","Mars","Oracle","Hero","AI"};
};
class authors: public books{
   public:
   string author_name[50];
   string a_name[5]={"B.N.Chatterjee","Musk","Jarvis","J.K.Rowling","Kalyani"};
};
class catalog:public authors{
  public:
  string items[50];
};
void changes(string data1,string data2){
    catalog obj3;
    obj3.items[index++]=data1+"\t"+data2;
}
int display(){
    int choice;
    cout<<"1.Add new book"<<endl;
    cout<<"2.Search for a book with the Title"<<endl;
    cout<<"3.Display all books"<<endl;
    cout<<"4.Exit"<<endl;
    cout<<"Enter your choice:"<<endl;
    cin>>choice;
    if(choice<1||choice>4){
        cout<<"Invalid Input! Please re-enter"<<endl;
        display();
    }
    else{
        return choice;
    }
}
void addBook(){
    books objA;
    authors objB;
    cout<<"Enter the new Book name:"<<endl;
    cin>>objA.book_name[index2++];
    cout<<"Enter the author name:"<<endl;
    cin>>objB.author_name[index3++];
    changes(objA.book_name[index2-1],objB.author_name[index3-1]);
}
int return_index(string search){
    int val=-1;
    books objO;
    for(int i=0;i<index2;i++){
        if(search.compare(objO.book_name[i])){
            val=i;
            break;
        }
    }
    return val;
}
void searchBook(){
    catalog objD;
    string search;
    cout<<"Enter the Book name you want to search:"<<endl;
    cin>>search;
     int searching=return_index(search);
     if(searching==-1){
        cout<<"Book not found in our collection."<<endl;
     }
     else{
        cout<<"Book found in our record!"<<endl;
        cout<<objD.items[searching]<<endl;
     }
}
void displayBooks(){
    catalog object;
    cout<<"Book Name\tAuthor Name"<<endl;
    for(int i=0;i<index;i++){
        cout<<object.items[i]<<endl;
    }
}
void process(){
    int choice=display();
    switch (choice){
        case 1:addBook();
        break;
        case 2:searchBook();
        break;
        case 3:displayBooks();
        break;
        case 4:
        exit(0);
    }
    if(choice!=4){
        process();
    }
}
int main(){
 books obj1;
 authors obj2;
 
 for(int i=0;i<5;i++){
   obj1.book_name[i]=obj1.name[i];
   obj2.author_name[i]=obj2.a_name[i];
   changes(obj1.book_name[i],obj2.author_name[i]);
 }
 process();
}