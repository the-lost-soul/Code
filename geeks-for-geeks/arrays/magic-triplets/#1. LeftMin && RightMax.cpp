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
    vector<int>rightMax(size , 0) , leftMin(size , 0) ;
    for(int i = 0 ; i < size ; i++)
    {
        for(int j = i + 1 ; j < size ; j++)
        {
            rightMax[i] += arr[i] < arr[j] ? 1 : 0 ;
            leftMin[j] += arr[i] < arr[j] ? 1 : 0 ;
        }
    }
    
    long ans = 0 ;
    for(int i = 0 ; i < size ; i++)
    {
        ans += rightMax[i]*leftMin[i] ;
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
