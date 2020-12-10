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
    // ith element of left array contains product of all elements
    // left to i of original array .
    int* left = new int[size] ;
    left[0] = 1 ;
    for(int i = 1 ; i < size ; i++)
    {
        left[i] = arr[i-1]*left[i-1] ;
    }
    // ith element of right array contains product of all elements
    // right to i of original array .
    int* right = new int[size] ;
    right[size-1] = 1 ;
    for(int i = size-2 ; i >= 0 ; i--)
    {
        right[i] = right[i+1]*arr[i+1] ;
    }
    for(int i = 0 ; i < size ; i++)
    {
        arr[i] = left[i]*right[i] ;
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
