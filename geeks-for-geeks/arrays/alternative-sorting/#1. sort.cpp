#include<iostream>
using namespace std ;

void scan(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
    cin >> arr[i] ;
}

void reverse(int arr[] , int start , int end)
{
    while(start < end)
    {
        swap(arr[start] , arr[end]) ;
        start ++ ;
        end -- ;
    }
}


void solve(int arr[] , int size , int rotationCount)
{
    reverse(arr , 0 , size - 1) ;
    reverse(arr , 0 , size - rotationCount - 1) ;
    reverse(arr , size - rotationCount , size - 1) ;
    
}

void print(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        cout<<arr[i]<<" " ;
    }
    cout<<endl ;
}


int main()
{
    int testcase ;
    cin >> testcase ;
    while(testcase --)
    {
        int size ;
        cin >> size ;
        int rotationCount ;
        cin >> rotationCount ;
        int arr[size] ;
        scan(arr , size) ;
        solve(arr , size , rotationCount%size) ;
        print(arr , size) ;
    }
    return 0 ;
}
