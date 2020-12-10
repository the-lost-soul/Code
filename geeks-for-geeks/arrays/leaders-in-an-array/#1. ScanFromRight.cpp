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
    // Stores the max seen till ith index .
    int max = INT_MIN ;
    for(int i = size-1 ; i >= 0 ; i--)
    {
        if(arr[i] >= max)
            max = arr[i] ;
        else arr[i] = -1 ;
    }
}

void printArray(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
        if(arr[i] != -1)cout << arr[i] << " " ;
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
	    printArray(arr ,size) ;
	}
	return 0;
}
