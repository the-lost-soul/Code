#include<bits/stdc++.h>
#include<iostream>
using namespace std ;

void scan(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
    cin >> arr[i] ;
}

int findPivot(int arr[] , int start , int end)
{
    if(start == end)return end ;
    if(start > end)return - 1 ;
    
    int mid = (start + end)/2 ;
    if(arr[mid] > arr[mid + 1] and arr[mid] > arr[mid - 1])return mid ;
    else if(arr[mid] > arr[mid - 1] and arr[mid] < arr[mid + 1])
    return findPivot(arr , mid + 1, end) ;
    else if(arr[mid - 1] > arr[mid] and arr[mid] > arr[mid + 1])
    return findPivot(arr , start , mid - 1) ;
}

int left(int arr[] , int key , int start , int end)
{
    int mid ;
    while(start <= end)
    {
        mid = (start + end)/2 ;
        if(arr[mid] == key)return mid ;
        else if(arr[mid] > key)end = mid - 1 ;
        else start = mid + 1 ;
    }
    return -1 ;
}

int right(int arr[] , int key , int start , int end)
{
    int mid ;
    while(start <= end)
    {
        mid = (start + end)/2 ;
        if(arr[mid] == key)return mid ;
        else if(arr[mid] < key)end = mid - 1 ;
        else start = mid + 1 ;
    }
    return -1 ;
}

int solve(int arr[] , int key , int start , int end)
{
    int pivot = findPivot(arr , start , end) ;
    if(arr[pivot] < key)return -1 ;
    else if(arr[pivot] == key)return pivot ;
    else
    {
        int answer = left(arr , key , 0 , pivot - 1) ;
        if(answer != -1)return answer ;
        
        return right(arr , key , pivot + 1 , end) ;
    }
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
        int key ;
        cin >> key ;
        cout<<solve(arr , key , 0 , size - 1)<<endl ;
    }
    return 0 ;
}
