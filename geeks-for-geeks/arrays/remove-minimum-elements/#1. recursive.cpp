#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void scanArray(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin >> arr[i] ;
}
/* Here we are considering every move */
int helper(int arr[] , int first , int last , int move)
{
    if(2*arr[first] > arr[last])return move ;
    return min(helper(arr , first + 1 , last , move + 1) ,
                helper(arr , first , last - 1 , move + 1)) ;
}
int solve(int arr[] , int size)
{
    sort(arr , arr + size) ;
    int move = 0 ;
    return helper(arr , 0 , size - 1 , move) ;
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
