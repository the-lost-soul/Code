#include<bits/stdc++.h>
#include <iostream>
using namespace std;

void scanArray(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin >> arr[i] ;
}

void segregate(int arr[] , int size)
{
    int count0 = 0 ;
    int count1 = 0 ;
    for(int i = 0 ; i < size ; i++)
    {
        if(arr[i] == 1)count1 ++ ;
        else count0 ++ ;
    }
    
    int index = 0 ;
    while(count0 --)
    {
        arr[index] = 0 ;
        index++ ;
    }
    
    while(count1--)
    {
        arr[index] = 1 ;
        index ++ ;
    }
}

void print(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
    cout<<arr[i]<<" " ;
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
	    segregate(arr , size) ;
	    print(arr , size) ;
	}
	return 0;
}
