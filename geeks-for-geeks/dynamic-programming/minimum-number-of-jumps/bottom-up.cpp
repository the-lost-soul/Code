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
    int jumps[size] ;
    for(int i = 0 ; i < size ; i++)jumps[i] = INT_MAX ;
    if(size == 0 or arr[0] == 0) return -1 ;
    jumps[0] = 0 ;
    for(int i = 1 ; i < size ; i++)
    {
        for(int j = 0 ; j < i ; j++)
        {
            if(i <= j + arr[j] and jumps[j] != INT_MAX)
                jumps[i] = min(jumps[i] , jumps[j] + 1) ;
        }
    }
    return jumps[size - 1] == INT_MAX ? -1 : jumps[size - 1] ;
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
