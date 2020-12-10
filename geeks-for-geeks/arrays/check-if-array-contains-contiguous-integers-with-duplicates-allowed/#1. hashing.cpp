#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void scanArray(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin >> arr[i] ;
}
string solve(int arr[] , int size)
{
    unordered_set<int>hash ;
    int minEle = INT_MAX , maxEle = INT_MIN ;
    // Hash all the array elements in a set . After hashing
    // set will contain only unique elements .
    for(int i = 0 ; i < size ; i++)
    {
        hash.insert(arr[i]) ;
        minEle = min(minEle , arr[i]) ;
        maxEle = max(maxEle , arr[i]) ;
    }
    // For each integer in the range [minEle , maxEle] check whether
    // it is present in set or not .
    for(int i = minEle ; i <= maxEle ; i++)
        if(hash.find(i) == hash.end())return "No" ;
    return "Yes" ;
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
