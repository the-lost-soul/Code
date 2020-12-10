#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void scanArray(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin >> arr[i] ;
}
void solve(int arr[] , int size)
{
    int low = 0 , high = 1 ;
    while(low < size and high < size)
    {
        if(arr[low] == 0 and arr[high] != 0)
        {
            swap(arr[low] , arr[high]) ;
            low++ ;
            high++ ;
        }
        else if(arr[low] != 0  and arr[high] == 0)
        {
            low++ ;
            high++ ;
        }
        else if(arr[low] == 0 and arr[high] == 0)
        {
            high++ ;
        }
        else if(arr[low] != 0 and arr[high] != 0)
        {
            low++ ;
            high++ ;
        }
    }
}
void printArray(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        cout << arr[i] << " " ;
    }
    cout << endl ;
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
	    printArray(arr , size) ;
	}
	return 0;
}
