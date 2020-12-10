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
    int mid = 0 , low = 0 , high = size - 1 ;
    int count = 0 ;
    while(low <= high)
    {
        mid = (low + high)/2 ;
        if(arr[mid] == 0)
        {
            count += high - mid + 1 ;
            high = mid - 1 ;
        }
        else low = mid + 1 ;
    }
    return count ;
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
