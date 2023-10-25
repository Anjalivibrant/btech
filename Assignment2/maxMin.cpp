#include<iostream>//Preprocessor Directives
using namespace std;//Namespace Declaration

int main(){//Main Function
    int size,max=0,min=0;
    cout << "Entere the size of the array: " << endl;
    cin >> size;
    int array[size];//array declaration
    cout<< "Enter Array elements: "<< endl;
    for(int i=0;i<size;i++)
    {
        cin>> array[i];
        if(array[i]>max)//condition for maximum
        {
            max=array[i];
        }
        if(array[i]<array[0])//condition for minimum
        {
            min=array[i];
        }
    }
    cout<< "The maximum value of the array: "<< max << endl;
    cout<< "The minimum value of the array: "<< min <<endl;
    return 0;//Return Statement
}//Function Closing Brace