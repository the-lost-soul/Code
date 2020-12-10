#include<iostream>
using namespace std ;

void scan(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
    cin >> arr[i] ;
}


int solve(int arr[] , int start , int end)
{
    // Base case -- When only one element is present
    // in array .
    if(start == end)return arr[end] ;
    
    int mid = (start + end)/2 ;
    
    /* If middle element is last element , then following
     * condition must be true . How we know this ? By the 
     * fact that if middle is our answer , then element
     * before it must be greater than it .
     */
    if(mid > start and arr[mid] < arr[mid - 1])return arr[mid] ;
    // If  mid is the maximum element then it must be followed
    // a minimum element also , as the array is rotated and sorted
    if(mid < end and arr[mid] > arr[mid + 1])return arr[mid + 1] ;
    
    // If mid is smaller than last element , then overall smallest
    // element must lie in left sub-array .
    if(arr[mid] <= arr[end])return solve(arr , start , mid - 1) ;
    
    return solve(arr , mid + 1 , end) ;
    
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
        cout<<solve(arr , 0 , size - 1)<<endl ;
    }
    return 0 ;
}
