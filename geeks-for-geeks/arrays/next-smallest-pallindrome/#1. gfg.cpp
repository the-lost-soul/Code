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
    int mid = size/2 ;
    int left = mid - 1 ;
    int right = size%2 == 0 ? mid : mid + 1 ;
    
    while((left >= 0 and right < size) and (arr[left] == arr[right]))
    {
        left-- ;
        right++ ;
    }
    
    bool leftSmaller = false ;
    if(left < 0 or arr[left] < arr[right])
    {
        leftSmaller = true ;
    }
    while(left >= 0 and right < size)
    {
        arr[right] = arr[left] ;
        left-- ;
        right++ ;
    }
    
    if(leftSmaller)
    {
        int carry = 1 ;
        if(size%2 == 1)
        {
            arr[mid] += carry ;
            carry = arr[mid]/10 ;
            arr[mid] = arr[mid]%10 ;
            left = mid - 1 ;
            right = mid + 1 ;
            
        }
        else 
        {
            left = mid - 1 ;
            right = mid ;
        }
        while(carry == 1)
        {
            arr[left] += carry ;
            arr[right] += carry ;
            carry = arr[left]/10 ;
            arr[left] = arr[left]%10 ;
            arr[right] = arr[right]%10 ;
            left-- ;
            right++ ;
            
        }
    }
}

void printArr(int arr[] , int size)
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
	    printArr(arr , size) ;
	}
	return 0;
}
