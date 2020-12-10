#include<bits/stdc++.h>
#include <iostream>
using namespace std;

void scanArray(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin >> arr[i] ;
}

int segregate(int arr[] , int size)
{
    int low = 0 ;
    int high = size - 1 ;
    int prefixSum = 0 ;
    for(int i = 0 ; i < size ; i++)
    {
        prefixSum += arr[i] ;
    }
    int leftSum = 0 ;
    for(int i = 0 ; i < size ; i++)
    {
        prefixSum -= arr[i] ;
        if(prefixSum == leftSum)return i+1 ;
        leftSum += arr[i] ;
        
    }
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
	    cout<<segregate(arr , size)<<" "<<endl ;
	}
	return 0;
}
