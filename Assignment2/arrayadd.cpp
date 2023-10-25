#include<iostream>//Preprocessor Directives
using namespace std;//Namespace Declaration

int main(){//Main Function
    int size,sum=0;
    cout << "Enter the Array Size: "<<endl;
    cin >> size;
    int array[size];//array declaration
    cout<< "Enter Array Elements: "<<endl;
    for(int i=0;i<size;i++)
    {
        cin >> array[i];
        sum+=array[i];
    }
    cout<< "The sum of all array elements is: "<< sum;
    return 0;//Return Statement
}//Function Closing Brace