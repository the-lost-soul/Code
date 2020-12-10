#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void scanArray(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin >> arr[i] ;
}
int solve(int arr[] , int size , int sum)
{
    sort(arr , arr + size) ;
    int left = 0 , right = size - 1 ;
    // Here ith index is fixed and we search for all other pairs .
    for(int i = 0 ; i < size - 2 ; i++)
    {
        left = i + 1 ;
        right = size - 1 ;
        while(left < right)
        {
            if(arr[i] + arr[right] + arr[left] == sum)return 1 ;
            if(arr[i] + arr[right] + arr[left] > sum)right-- ;
            else if(arr[i] + arr[right] + arr[left] < sum)left++ ;
            
        }
    }
    return 0 ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    int size ;
	    int sum ;
    	cin >> size ;
    	cin >> sum ;
    	int arr[size] ;
    	scanArray(arr , size) ;
	    cout << solve(arr , size , sum) << endl ;
	}
	return 0;
}
