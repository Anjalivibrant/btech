/*WAP in C++ to multiply like the actual matrix multiplication with rows and columns*/
#include<iostream>
using namespace std;
/*void multi()
{
    int array3[size][size];//the array to store the product of the two arrays
    int row=0,row2=1;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {// add according to the size of array
             array3[i][j]=(array1[i][j]*array2[i][row])+(array1[i][j]*array2[row2][row]);
        } 
        row+=1;row2++;
    }   
}*/
int main()
{
    int size;
    cout << "Enter the size of the array: " << endl;
    cin >> size;
    int array1[size][size],array2[size][size];//array declaration
    cout<< "Enter first Array elements: "<< endl;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
           cin>> array1[i][j];
        }  
    }
    cout<< "Enter second Array elements: "<< endl;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
           cin>> array2[i][j];
        }  
    }
    int array3[size][size];//the array to store the product of the two arrays
    int row=0,row2=1;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
             array3[i][j]=(array1[i][j]*array2[i][row])+(array1[i][j]*array2[row2][row]);
        } 
        row+=1;row2++;
    }
    cout<< "The array product of both the arrays is: "<<endl;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
           cout<<array3[i][j]<<" ";
        }
        cout<<endl;
    } 
    return 0;
}