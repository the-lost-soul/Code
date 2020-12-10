#include<bits/stdc++.h>
#include<iostream>
using namespace std ;

void scan(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
    cin >> arr[i] ;
}

void solve(int arr[] , int size , int rotationCount)
{
    for(int i = rotationCount ; i < rotationCount + size ; i++)
    {
        cout<<arr[i%size]<<" " ;
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
    }
    return 0 ;
}
