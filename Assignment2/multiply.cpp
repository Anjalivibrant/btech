#include<iostream>
using namespace std;
int main()
{
    int size;
    cout << "Enter the size of the array: " << endl;
    cin >> size;
    int array1[size],array2[size];//array declaration
    cout<< "Enter first Array elements: "<< endl;
    for(int i=0;i<size;i++)
    {
        cin>> array1[i];
    }
    cout<< "Enter second Array elements: "<< endl;
    for(int i=0;i<size;i++)
    {
        cin>> array2[i];
    }
    int array3[size];//the array to store the product of the two arrays
    for(int i=0;i<size;i++)
    {
        array3[i]=(array1[i]*array2[i]);
    }
    cout<< "The array product of both the arrays is: "<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<array3[i]<<" ";
    }
    return 0;
}