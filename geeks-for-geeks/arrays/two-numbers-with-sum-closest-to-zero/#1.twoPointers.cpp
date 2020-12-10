#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void scanArray(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin>>arr[i] ;
}
void solve(int arr[] , int size)
{
    sort(arr , arr + size) ;
    int left = 0 , right = size - 1 ;
    int sum = INT_MAX ;
    while(left < right)
    {
        if(arr[left] + arr[right] == 0)
        {
            sum = 0 ;
            break ;
        }
        if(abs(sum) > abs(arr[left] + arr[right]))
            sum = arr[left] + arr[right] ;
        
        if(arr[left] + arr[right] > 0)right-- ;
        else left++ ;
    }
    cout << sum << endl ;
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
