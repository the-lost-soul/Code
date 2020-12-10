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
    int left = 0 ;
    int right = size - 1 ;
    while(left < right)
    {
        // Both the element is at correct position , so
        // shrink both pointers towards each other .
        if(arr[left] == 0 and arr[right] == 1)
        {
            left++ ;
            right-- ;
        }
        // If element at left is set then move towards right .
        else if(arr[left] == 0 and arr[right] == 0)left++ ;
        // If element at right is set , then move towards left .
        else if(arr[left] == 1 and arr[right] == 1)right-- ;
        // If none of the element at left and right position
        // is set , then swap both and shrink left and right
        // pointers towards each other .
        else if(arr[left] == 1 and arr[right] == 0)
        {
            swap(arr[left] , arr[right]) ;
            left++ ;
            right-- ;
        }
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
