/* The idea behind this is to use modified quick sort .
 * Here we will modify quick-sort algo in a way that we
 * have to recur only for one side of array depending upon
 * relation between k and pivot .
 
 * STEPS -->
 * 1.)Divide the array into two parts around a pivot 
 * element , after this we will get all elements less
 * the pivot element on the left side of pivot and all
 * element greater than pivot on the right side of pivot .
 *
 * 2.)Now check whether element at pivot index is the kth 
 * smallest or not , if yes return it , otherwise recur 
 * either for left side of pivot(if k is smaller than pivot)
 * or recur for right side of pivot(if k is greater than pivot) .
 */
#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int partition(int arr[] , int start , int end)
{
    int pivot = arr[end] ;
    
    int j = start ;
    for(int i = start ; i < end ; i++)
    {
        if(arr[i] < pivot)
        {
            swap(arr[i] , arr[j]) ;
            j ++ ;
        }
    }
    swap(arr[j] , arr[end]) ;
    return j ;
}


int solve(int arr[] , int start ,  int end , int k)
{
    int pivot = partition(arr , start , end) ;
    
    // If we found the kth smallest elemnt return it .
    if(pivot == k - 1)return arr[pivot] ;
    // Recur for right side , if k is smaller than pivot .
    else if(pivot > k - 1)return solve(arr , start , pivot - 1 , k) ;
    else return solve(arr , pivot + 1 , end , k) ;
}

void scan(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        cin >> arr[i] ;
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
	    int k ;
	    cin >> k ;
	    cout << solve(arr , 0 , size - 1 , k) << endl ;
	}
	return 0;
}
