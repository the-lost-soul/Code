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
    vector<int>LIS(size , 1) ;
    for(int i = 1 ; i < size ; i++)
    {
        for(int j = 0 ; j < i ; j++)
        {
            if(arr[i] > arr[j] and LIS[i] < LIS[j] + 1)
            {
                LIS[i] = LIS[j] + 1 ;
            }
        }
    }
    
    vector<int>LDS(size , 1) ;
    for(int i = size - 2 ; i >= 0 ; i--)
    {
        for(int j = size - 1 ; j > i ; j--)
        {
            if(arr[i] > arr[j] and LDS[i] < LDS[j] + 1)
            {
                LDS[i] = LDS[j] + 1 ;
            }
        }
    }
    
    int len = INT_MIN ;
    for(int i = 0 ; i < size ; i++)
    {
        int  tempLen = LDS[i] + LIS[i] - 1 ;
        len = max(tempLen , len) ;
    }
    return len ;
    
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
