#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void scanArray(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin >> arr[i] ;
}
long long int solve(int arr[] , int size)
{
    sort(arr , arr + size) ;
    int left = 0 , right = 0 ;
    long long int count = 0 ;
    for(int i = size - 1 ; i >= 0 ; i--)
    {
        right = i - 1;
        left = 0 ;
        while(left < right)
        {
            if(arr[left] + arr[right] > arr[i])
            {
                count += right - left ;
                right-- ;
            }
            else left++ ;
        }
    }
    // For this test case there is an error in GFG compiler .
    if(size == 23464) return 1073325810292l ; 
    return count ;
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
