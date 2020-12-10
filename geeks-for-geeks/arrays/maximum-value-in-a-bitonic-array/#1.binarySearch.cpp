#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void scanArray(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin >> arr[i] ;
}
int solve(int arr[] , int start , int end)
{
    // Base case
    if(start == end)return arr[start] ;
    
    // When two elements are present , then if condition
    // can give error "array out of bound access" .
    if(start + 1 == end)return max(arr[start] , arr[end]) ;
    
    int mid = (start + end)/2 ;
    // If we reach the pivot element .
    if(arr[mid] > arr[mid - 1] and arr[mid] > arr[mid + 1])
        return arr[mid] ;
    // Recur for right sub-array if current element is
    // larger than element before it .
    if(arr[mid] > arr[mid - 1])return solve(arr , mid + 1 , end) ;
    else if(arr[mid] <= arr[mid - 1])return solve(arr , start , mid - 1) ;
    
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
	    cout << solve(arr , 0 , size - 1) << endl ;
	}
	return 0;
}
