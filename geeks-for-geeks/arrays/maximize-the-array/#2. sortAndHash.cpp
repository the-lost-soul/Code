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
bool comp(int a , int b)
{
    return a > b ;
}
vector<int>solve(int arr1[] , int arr2[] , int size)
{
    int arr[2*size] ;
    for(int i = 0 ; i < size ; i++)
    {
        arr[i] = arr1[i] ;
        arr[i + size] = arr2[i] ;
    }
    // Sort in decreasing order .
    sort(arr , arr + 2*size , comp) ;
    int k = size ;
    unordered_map<int , int>hash ;
    /* Hash the first k greatest element , if present .Why if present ?
     * Because there may be a case when size of array is greater than 
     * the number of unique element .
     * Eg -- arr1 = [1 , 1 , 1 , 2 , 2 , 2 , 2]
             arr2 = [1 , 2 , 1 , 2 , , 2 , 1 ,2]
             Here k = 7 but number of unique elemnt is just 2 , hence the
             ansVec will have only two element because we want the elements
             to be unique
     */
    for(int i = 0 ; i < 2*size , k > 0 ; i++)
    {
        if(hash.find(arr[i]) == hash.end())
        {
            hash[arr[i]] = 1 ;
            k-- ;
        }
    }
    
    vector<int>ansVec ;
    for(int i = 0 ; i < size ; i++)
    {
        // If the current element of arr2 is present in hash table and it has yet
        // not been visited , then visit it and insert it to ansVec .
        if(hash.find(arr2[i]) != hash.end() and hash[arr2[i]] != -1)
        {
            hash[arr2[i]] = -1 ;
            ansVec.push_back(arr2[i]) ;
        }
    }
    // Do as above for array1 .
    for(int i = 0 ; i < size ; i++)
    {
        if(hash.find(arr1[i]) != hash.end() and hash[arr1[i]] != -1)
        {
            hash[arr1[i]] = -1 ;
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
