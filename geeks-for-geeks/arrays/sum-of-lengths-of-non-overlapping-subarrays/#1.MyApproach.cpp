#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void scanArray(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin >> arr[i] ;
}
int solve(int arr[] , int size , int num)
{
    bool foundNumInCurrSubArray = false ;
    int totalLength = 0 ;
    int start = 0 ;
    int index = 0 ;
    while(index < size)
    {
        start = index ;
        // Get the sub-array , till we don't reach an element
        // greater than num or till end .
        while(index < size and arr[index] <= num)
        {
            if(arr[index] == num)
                foundNumInCurrSubArray = true ; 
            
            index++ ;
        }
        // If it's true then cyurr sub-array contains the desired
        // number .
        if(foundNumInCurrSubArray)
        {
            // Length of sub-array containing the desired num .
            totalLength += (index - start) ;
            foundNumInCurrSubArray = false ;
        }
        index++ ;
    }
    return totalLength ;
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
    	int num ;
    	cin >> num ;
	    cout << solve(arr , size , num) << endl ;
	}
	return 0;
}
