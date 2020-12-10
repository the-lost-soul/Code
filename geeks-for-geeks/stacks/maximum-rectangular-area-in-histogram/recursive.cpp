#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void scanArray(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin >> arr[i] ;
}
int minHeight(int arr[] , int left , int right)
{
    int height = INT_MAX ;
    for(int i = left ; i <= right ; i++)
    {
        height = min(height , arr[i]) ;
    }
    return height ;
}
int maxArea(int arr[] , int left , int right , int size)
{
    if(left > right)return 0 ;
    int height = minHeight(arr , left , right) ;
    int area = height*size ;
    return max(area , max(maxArea(arr , left + 1 , right , size - 1) 
            , maxArea(arr , left , right - 1 , size - 1))) ;
}
void solve(int arr[] , int size)
{
    int left = 0 , right = size - 1 ;
    cout<<maxArea(arr , left , right , size)<<endl ;
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
	    solve(arr , size) ;
	}
	return 0;
}
