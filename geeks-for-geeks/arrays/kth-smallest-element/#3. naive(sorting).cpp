#include<bits/stdc++.h>
#include <iostream>
using namespace std;

void scan(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        cin >> arr[i] ;
    }
}

int solve(int arr[] , int size , int k)
{
    sort(arr , arr + size) ;
    return arr[k - 1] ;
}
int main() 
{
	int testcase ;
	cin >> testcase ;
	while(testcase --)
	{
	    int size ;
	    cin >> size ;
	    int arr[size] ;
	    scan(arr , size) ;
	    int k ;
	    cin >> k ;
	    cout << solve(arr , size , k) << endl ;
	}
	return 0;
}
