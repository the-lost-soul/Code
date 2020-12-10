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
    // Stores the element on left side which is smaller
    // than current element .
    int right[size] ;
    right[0] = arr[0] ;
    for(int i = 1 ; i < size ; i++)
    {
        right[i] = min(arr[i] , right[i - 1]) ;
    }
    // Stores the element on right side which is larger
    // than current element .
    int left[size] ;
    left[size - 1] = arr[size - 1] ;
    for(int i = size - 2 ; i >= 0 ; i--)
    {
        left[i] = max(arr[i] , left[i + 1]) ;
    }
    int i = 0 , j = 0 , ans = 0 ;
    while(i < size and j < size)
    {
        if(right[i] <= left[j])
        {
            ans = max(ans , j - i) ;
            j++ ;
        }
        else i++ ;
    }
    return ans ;
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
