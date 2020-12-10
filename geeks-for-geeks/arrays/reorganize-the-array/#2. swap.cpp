#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void scan(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin >> arr[i] ;
}

void answer(int arr[] , int size)
{
    for(int i = 0 ; i < size ;)
    {
        if(arr[i] >= 0 && arr[i] != i)
            swap(arr[i] , arr[arr[i]]) ;
        else i ++ ;
    }
}

void print(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
        cout<<arr[i]<< " " ;
    cout << endl ;
}

int main() 
{
    int testcase ;
    cin >> testcase ;
    while(testcase --)
    {
        int size ;
        cin >> size ;
        int arr[size] ;
        scan(arr , size) ;
        answer(arr , size) ;
        print(arr , size) ;
    }
	return 0;
}
