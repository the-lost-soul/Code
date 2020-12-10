#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void scanArray(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
    cin >> arr[i] ;
}
void solve(int arr[] , int size , int window)
{
    for(int i = 0 ; i <= size - window ; i++)
    {
        for(int j = i ; j < i + window ; j++)
        {
            if(arr[j] < 0)
            {
                cout<<arr[j]<<" " ;
                break ;
            }
            if(j == i + window - 1)cout<<"0 " ;
            
        }
    }
    
    cout<<endl ;
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
	    int window ;
	    cin >> window ;
	    solve(arr , size , window) ;
	}
	return 0;
}
