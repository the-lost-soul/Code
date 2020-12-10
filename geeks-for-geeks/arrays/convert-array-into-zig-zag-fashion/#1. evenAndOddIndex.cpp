#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void scanArray(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin >> arr[i] ;
}
void solve(int arr[] , int size)
{
    for(int i = 1 ; i < size ; i++)
    {
        // If current index is odd , then current element must
        // be greater than previous else we sawp them .
        if(i%2 != 0)
        {
            if(arr[i] < arr[i-1])swap(arr[i] , arr[i-1]) ;
        }
        // If index is even , then curr element must be less than
        // previous else we swap them .
        else
        {
            if(arr[i] > arr[i-1])swap(arr[i] , arr[i-1]) ;
        }
    }
}

void printArray(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)cout << arr[i] << " " ;
    cout << endl ;
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
	    solve(arr , size) ;
	    printArray(arr , size) ;
	}
	return 0;
}
