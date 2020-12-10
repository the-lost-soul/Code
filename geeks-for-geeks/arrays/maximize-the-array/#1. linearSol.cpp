#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void scanArray(int arr1[] , int arr2[] , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin >> arr1[i] ;
    for(int i = 0 ; i < size ; i++)
        cin >> arr2[i] ;
}
vector<int>solve(int arr1[] , int arr2[] , int size)
{
    int arr[10] ;
    memset(arr , -1 , sizeof(arr)) ;
    
    for(int i = 0 ; i < size ; i++)
    {
        arr[arr1[i]]++ ;
        arr[arr2[i]]++ ;
    }
    
    // Get the upper bound of element which can be added to new vector .
    int upperBound = 0 ;
    for(int i = 9 ; i >= 0 ; i--)
    {
        if(arr[i] != -1)
        {
            upperBound = i ;
            break ;
        }
    }
    // Get the lower bound of element which can be added to new vector .
    int  upperBoundIndex = upperBound , tempSize = size , lowerBound = 0 ;
    while(upperBoundIndex >= 0 and tempSize > 0)
    {
        if(arr[upperBoundIndex] != -1)
        {
            lowerBound = upperBoundIndex ;
            tempSize-- ;
        }
        upperBoundIndex-- ;
    }
    
    vector<int>ansVec ;
    for(int i = 0 ; i < size ; i++)
    {
        /* Since array2 has more priority , so we start putting elements from arr2 .
         * If the current number is in range i.e it is one of the desired "k" greatest
         * unique element , then put it in ansVec.
         * To check whether the current element is already inserted in ansVec or not
         * we just have to see whether arr[arr2[i]] == -1 or not , if -1 then it is a
         * unique element else we have already inserted it .
         */
        if(arr2[i] >= lowerBound and arr2[i] <= upperBound and arr[arr2[i]] != -1)
        {
            arr[arr2[i]] = -1 ;
            ansVec.push_back(arr2[i]) ;
        }
    }
    // Do as above for array1 .
    for(int i = 0 ; i < size ; i++)
    {
        if(arr1[i] >= lowerBound and arr1[i] <= upperBound and arr[arr1[i]] != -1)
        {
            arr[arr1[i]] = -1 ;
            ansVec.push_back(arr1[i]) ;
        }
    }
    return ansVec ;
}
void print(vector<int>ansVec)
{
    for(int i = 0 ; i < ansVec.size() ; i++)
    {
        cout << ansVec[i] << " " ;
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
    	int arr1[size] , arr2[size] ;
    	scanArray(arr1 , arr2 , size) ;
	    vector<int>ansVec = solve(arr1 , arr2 , size) ;
	   print(ansVec) ;
	}
	return 0;
}
