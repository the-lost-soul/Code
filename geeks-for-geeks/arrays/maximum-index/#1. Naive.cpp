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
    if(size == 1)return 0 ;
    int ans = INT_MIN ;
    for(int i = 0 ; i < size ; i++)
    {
        for(int j = i + 1 ; j < size ; j++)
        {
            if(arr[i] <= arr[j])ans = max(ans , j - i) ;
        }
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
