#include<bits/stdc++.h>
#include<iostream>
using namespace std;
/* The brute forcw works something like this , for an element in arr1
 * we check in arr2 whether there exists an element or not such that
 * swapping them makes sum of both arrays equal .
 * Formula -- sumArr1 - arr1[i] + arr2[j] == sumArr2 - arr2[j] + arr1[i]
 * The above formula can be re-written as -- 
 * sumArr1 - sumArr2 == 2*arr1[i] - 2*arr2[j] or diff == 2*(arr1[i] - arr2[j])
 * Hence , the question has now reduced to finding pairs , double of whose
 * difference equals the difference b/w sumArr1 and sumArr2 .
 */
void scanArray(int arr1[] , int arr2[] , int size1 , int size2)
{
    for(int i = 0 ; i < size1 ; i++)
        cin >> arr1[i] ;
        
    for(int i = 0 ; i < size2 ; i++)
        cin >> arr2[i] ;
}
int solve(int arr1[] , int arr2[] , int size1,  int size2)
{
    // Get the total sum of individual arrays .
    int sum1  = 0 ;
    for(int i = 0 ; i < size1 ; i++)sum1 += arr1[i] ;
    int sum2 = 0 ;
    for(int i = 0 ; i < size2 ; i++)sum2 += arr2[i] ;
    
    int diff = sum1 - sum2 ;
    unordered_set<int>hash ;
    for(int i = 0 ; i < size1 ; i++)hash.insert(2*arr1[i]) ;
    for(int i = 0 ; i < size2 ; i++)
    {
        if(hash.find(diff + 2*arr2[i]) != hash.end())return 1 ;
    }
    return -1 ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    int size1 , size2 ;
    	cin >> size1 >> size2 ;
    	int arr1[size1] , arr2[size2] ;
    	scanArray(arr1 , arr2 , size1 , size2) ;
	    cout << solve(arr1 , arr2 , size1 , size2) << endl ;
	}
	return 0;
}
