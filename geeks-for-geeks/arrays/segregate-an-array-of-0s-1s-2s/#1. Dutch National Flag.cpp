#include<bits/stdc++.h>
#include <iostream>
using namespace std;

void scanArray(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin >> arr[i] ;
}

void segregate(int arr[] , int size)
{
    int low = 0 ;
    int mid = 0 ;
    int high = size -1 ;
    while(mid <= high)
    {
        if(arr[mid] == 0)
        {
            swap(arr[low] , arr[mid]) ;
            low++ ;
            mid++ ;
        }
        else if(arr[mid] == 1)mid++ ;
        else if(arr[mid] == 2)
        {
            swap(arr[mid] , arr[high]) ;
            high-- ;   
        }
    }
}

void print(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
    cout<<arr[i]<<" " ;
    cout<<endl ;
}
int main() 
{
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    int size ;
	    cin >> size ;
	    int arr[size] ;
	    scanArray(arr , size) ;
	    segregate(arr , size) ;
	    print(arr , size) ;
	}
	return 0;
}
