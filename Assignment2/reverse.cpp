#include<iostream>//Preprocessor Directives
using namespace std;//Namespace Declaration
void display(int size, int array[])
{
    for(int i=0;i<size;i++)
    {
        cout<< array[i]<< " ";
    }
}
int main(){//Main Function
   int size;
    cout << "Enter the size of the array: " << endl;
    cin >> size;
    int array[size];//array declaration
    cout<< "Enter Array elements: "<< endl;
    for(int i=0;i<size;i++)
    {
        cin>> array[i];
    }
    cout<< "The elements are: "<<endl;
    display(size,array);
    //the reverse of the array is done using for loop
    int i,j,temp;
    for(i=0,j=size-1;i<j;i++,j--)
    {
        temp=array[i];
        array[i]=array[j];
        array[j]=temp;
    }
    cout<<"\nThe reverse of the given array is: "<<endl;
    display(size,array);
    return 0;//Return Statement
}//Function Closing Brace