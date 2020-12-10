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
    unordered_map<int , int>hash ;
    for(int i = 0 ; i < size ; i++)hash[arr[i]]++ ;
    for(int i = 0 ; i < size ; i++)if(hash[arr[i]] > 1)return i + 1 ;
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
