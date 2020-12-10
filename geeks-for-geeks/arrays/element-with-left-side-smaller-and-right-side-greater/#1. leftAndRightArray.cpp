#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void scanArray(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin >> arr[i] ;
}
int solve(int arr[] , int size)
{
    int maxSoFar = arr[0] ;
    // It contains only the deserving candidates i.e those elements
    // on whose left all elements are smaller or equal than it .
    int left[size] = {} ;
    maxSoFar = arr[size-1] ;
    for(int i = size-2 ; i >= 0 ; i--)
    {
        
        if(arr[i] <= maxSoFar and i != 0)
        {
            maxSoFar = arr[i] ;
            left[i] = arr[i] ;
        }
    }
    
    // It contains only those elements on whose right all elements are
    // greater than it .
    int right[size] = {} ;
    for(int i = 1 ; i < size ; i++)
    {
        if(i == size-1)right[i] = 0 ;
        else
        {
            if(arr[i] >= maxSoFar)
            {
                maxSoFar = arr[i] ;
                right[i] = arr[i] ;
            }
        }
    }
    // Now compare both the arrays and return the first matched element .
    for(int i = 0 ; i < size ; i++)
    {
        if(right[i] == left[i] and right[i] != 0)return right[i] ;
    }
    return -1 ;
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
	    cout << solve(arr , size) << endl ;
	}
	return 0;
}
