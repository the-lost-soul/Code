#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void scanArray(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin>>arr[i] ;
}
int solve(int arr[] , int size , int key)
{
    // Store count of all elements in a hash table .
    unordered_map<int , int>hash ;
    for(int i =  0 ; i < size ; i++)
    {
        hash[arr[i]]++ ;
    }
    /* Iterate through all elements get the count of
     * pairs which satisfies the pair sum criteria .
     * Remember every pair is counted twice here .
     */
    int count = 0 ;
    for(int  i = 0 ; i < size ; i++)
    {
        count += hash[key - arr[i]] ;
        // For a pair(arr[i] , arr[i]) , decrement the count
        // because it's not a valid pair .
        if(key - arr[i] == arr[i])count-- ;
    }
    
    // Since every element is counted twice , hence divide
    // by two .
    return count/2 ;
    
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    int size ;
	    int key ;
    	cin >> size ;
    	cin >> key ;
    	int arr[size] ;
    	scanArray(arr , size) ;
	    cout << solve(arr , size , key) << endl ;
	}
	return 0;
}
