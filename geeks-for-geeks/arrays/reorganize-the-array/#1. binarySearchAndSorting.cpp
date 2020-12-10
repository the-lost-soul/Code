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
    // Sorting is required because the in-built binary search
    // function works only for sorted containers .
    sort(arr , arr + size) ;
    
    for(int i = 0 ; i < size ; i++)
    {
        // If element found , then set the element to its correct
        // position i.e i .
        if(binary_search(arr , arr + size , i))
            arr[i] = i ;
        else arr[i] = -1 ;
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
