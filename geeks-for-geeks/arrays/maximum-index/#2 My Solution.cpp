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
    int index = 0 ;
    int ans = 0 ;
    for(int i = 0 ; i < size ; i++)
    {
        for(int j = index ; j < size ; j++)
        {
            if(arr[i] <= arr[j])
            {
                ans = max(ans , j - i) ;
                index = j ;
            }
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
