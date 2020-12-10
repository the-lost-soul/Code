#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void scanArray(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
    cin >> arr[i] ;
}
void solve(int arr[] , int size)
{
    /* Traverse the array and use this element as an index
     * and mark that index with negative value of element .
     * If we got any index with negative value , then that 
     * is our repeating element .
     */
    int repeating ;
    for(int i = 0 ; i < size ; i++)
    {
        if(arr[abs(arr[i]) - 1] > 0)
            arr[abs(arr[i]) - 1] = - arr[abs(arr[i]) - 1] ;
        else repeating = abs(arr[i]) ;
    }
    
    /* The missing element will be that index which will be
    * unmarked .
    */
    int missing ;
    for(int i = 0 ; i < size ; i++)
    {
        if(arr[i] > 0)
        {
            missing = i + 1 ;
            break ;
        }
    }
    cout<<repeating<<" "<<missing<<endl ;
    
    
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
	    solve(arr , size) ;
	}
	return 0;
}
