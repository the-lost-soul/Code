#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void scanArray(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin >> arr[i] ;
}
bool strictlyAscending(int arr[] , int size)
{
    for(int i = 0 ; i < size - 1 ; i++)
    {
        if(arr[i] < arr[i + 1])return false ;
    }
    return true ;
}
bool strictlyDescending(int arr[] , int size)
{
    for(int i = 0 ; i < size - 1 ; i++)
    {
        if(arr[i] > arr[i + 1])return false ;
    }
    return true ;
}
int find(int arr[] , int size , int start)
{
    int justMaxIndex = start ;
    for(int i = start + 1 ; i < size ; i++)
    {
        if(arr[i] > arr[start - 1] and arr[justMaxIndex] > arr[i])
        {
            justMaxIndex = i ;
        }
    }
    return justMaxIndex ;
}
void solve(int arr[] , int size)
{
    // Testcase -- 123 Output is -- 132
    if(strictlyAscending(arr , size))
    {
        swap(arr[size - 1] , arr[size - 2]) ;
    }
    else if(strictlyDescending(arr , size))
    {
        reverse(arr , arr + size) ;
    }
    else
    {
        int i = size - 1 ;
        // Get the first element from right which is smaller than it's previous
        while(arr[i - 1] >= arr[i])i-- ;
        int pivot = i - 1 ;
        // Get the first element's index which is just greater than the pivot's
        // index element .
        int indexOfEleOnLeftJustGreaterThanPivot = find(arr , size , pivot + 1) ;
        // Swap both the element
        swap(arr[pivot] , arr[indexOfEleOnLeftJustGreaterThanPivot]) ;
        // Sort the elements of right side present after the pivot index element .
        sort(arr + pivot + 1 , arr + size) ;
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
	    printArray(arr, size) ;
	}
	return 0;
}
