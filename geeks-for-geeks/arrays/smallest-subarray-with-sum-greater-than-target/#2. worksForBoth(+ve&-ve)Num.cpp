/* Works when array contains both positive or negative integer or any one of them . */
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void scanArray(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin >> arr[i] ;
}
int solve(int arr[] , int size , int target)
{
    int sum = 0 , subArrayStart = 0 , minLen = INT_MAX ;
    for(int i = 0 ; i < size ; i++)
    {
        sum += arr[i] ;
        // If current sub-array has negative sum and target is positive .
        if(sum < 0 and target > 0)
        {
            subArrayStart = i + 1 ;
            sum = 0 ;
            continue ;
        }
        // If we get a sub-array whose sum is greater than target
        if(sum > target)
        {
            /* Try to decrease the length of sub-array(if possible) , 
             * till the time sum is greater than target .
             * Length will decrease only when on subtracting the 
             * first element of current sub-array from sum , we get
             * a value greater than target , as it will implies that 
             * ahead we still have a sub-array whose sum is greater tha
             * target and length is smaller than current sub-array length .
             */
            while(sum - arr[subArrayStart] > target)
            {
                sum -= arr[subArrayStart] ;
                subArrayStart++ ;
            }
            minLen = min(minLen , i - subArrayStart + 1) ;
        }
    }
    return minLen == INT_MAX ? -1 : minLen ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    int size ,target ;
    	cin >> size >> target ;
    	int arr[size] ;
    	scanArray(arr , size) ;
	    cout << solve(arr , size , target) << endl ;
	}
	return 0;
}
