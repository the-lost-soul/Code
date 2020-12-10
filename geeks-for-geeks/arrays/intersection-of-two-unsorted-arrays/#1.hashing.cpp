#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void scanArray(int arr1[] , int arr2[] , int size1 , int size2)
{
    for(int i = 0 ; i < size1 ; i++)
        cin >> arr1[i] ;
    
    for(int i = 0 ; i < size2 ; i++)
        cin >> arr2[i] ;
}
int solve(int arr1[] , int arr2[] , int size1 , int size2)
{
    unordered_map<int , int>hash ;
    
    for(int i = 0 ; i < size1 ; i++)
        hash[arr1[i]]++ ;
    
    int count = 0 ;
    for(int i = 0 ; i < size2 ; i++)
    {
        if(hash.find(arr2[i]) != hash.end() and hash[arr2[i]] != -1)
        {
            count++ ;
            hash[arr2[i]] = -1 ;
        }
    }
    return count ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    int size1 ,size2 ;
    	cin >> size1 >> size2 ;
    	int arr1[size1] , arr2[size2] ;
    	scanArray(arr1 , arr2 , size1 , size2) ;
	    cout << solve(arr1 , arr2 , size1 , size2) << endl ;
	}
	return 0;
}
