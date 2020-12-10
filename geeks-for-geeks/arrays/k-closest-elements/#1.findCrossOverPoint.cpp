#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void scanArray(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin >> arr[i] ;
}
int binarySearch(int arr[] , int start , int end , int key)
{
    int mid = 0 ;
    while(start < end)
    {
        mid = (start+end)/2 ;
        if(arr[mid] == key)return mid ;
        else if(arr[mid] > key)end = mid-1 ;
        else start = mid+1 ;
    }
}
void solve(int arr[] , int k , int key , int size)
{
    int pivot = binarySearch(arr , 0 , size - 1 , key) ;
    int start = pivot - k/2 , end = pivot + k/2 ;
    if(start < 0 and end >= size)
    {
        start = 0 ;
        end = size-1 ;
    }
    // If left side of key has less elements than required , 
    // so we increase the number of elements of right side
    else if(start < 0)
    {
        end += abs(start) ;
        start = 0 ;
    }
    // If right side of key has less elements than required , then
    // we increase the number of elements on right side of key .
    else if(end >= size)
    {
        start -=(end - size + 1) ;
        end = size-1 ;
    }
    // It is used to print key value , when there is more than
    // one key element present .
    bool foundKeyOnce = true ;
    for(int i = start ; i <= end ; i++)
    {
        if(foundKeyOnce)
        {
            if(arr[i] == key)foundKeyOnce = false ;
            else cout << arr[i] << " " ;
        }
        else cout << arr[i] << " " ;
    }
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
    	int k , key ;
    	cin >> k >> key ;
	    solve(arr , k , key , size) ;
	}
	return 0;
}
