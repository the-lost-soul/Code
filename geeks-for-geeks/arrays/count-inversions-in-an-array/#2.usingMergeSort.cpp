#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void scanArray(long int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin >> arr[i] ;
}
long int merge(long int arr[] , long int temp[] , int start , int mid , int end)
{
    long int invCount = 0 ;
    // Points to current element of temp array .
    int index = start ;
    int left = start ;
    int right = end ;
    int middle = mid ;
    while(left < mid and middle <= end)
    {
        // Inversion
        if(arr[left] > arr[middle])
        {
            temp[index] = arr[middle] ;
            index++ ;
            middle++ ;
            /* If current element of left sub-array is larger than
             * current element of right sub-array , so all other 
             * elements present in left sub-array will also contribute
             * to inversion , hence we do (mid - left) ;
             */
            invCount += mid - left ;
        }
        else if(arr[left] <= arr[middle])
        {
            temp[index] = arr[left] ;
            index++ ;
            left++ ;
        }
    }
    // If elements are present in left sub-array , then push
    // them to temp .
    while(left < mid)
    {
        temp[index] = arr[left] ;
        index++ ;
        left++ ;
    }
    while(middle <= end)
    {
        temp[index] = arr[middle] ;
        middle++ ;
        index++ ;
    }
    // copy the elements back to original array .
    for(int i = start ; i <= end ; i++)
    {
        arr[i] = temp[i] ;
    }
    return invCount ;
}
long int mergeSortHelper(long int arr[] , long int temp[] , int start , int end)
{
    long int invCount = 0 ;
    if(start < end)
    {
        int mid = (start + end)/2 ;
        invCount = mergeSortHelper(arr , temp , start , mid) ;
        invCount += mergeSortHelper(arr , temp , mid + 1 , end) ;
        invCount += merge(arr , temp , start , mid + 1 , end) ;
        
    }
    return invCount ;
}
long int solve(long int arr[] , int size)
{
    long int temp[size] ;
    return mergeSortHelper(arr , temp , 0 , size - 1) ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    int size ;
    	cin >> size ;
    	long int arr[size] ;
    	scanArray(arr , size) ;
	    cout << solve(arr , size) << endl ;
	}
	return 0;
}
