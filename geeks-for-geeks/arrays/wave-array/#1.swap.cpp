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
    int fast = 1 , slow = 0 ;
    // Swap adjacent elements
    while(fast < size)
    {
        swap(arr[fast] , arr[slow]) ;
        slow = fast + 1 ;
        fast += 2 ;
    }
}
void printArray(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)cout<<arr[i]<<" " ;
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
