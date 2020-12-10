#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void scanArray(long arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin >> arr[i] ;
}
long solve(long arr[] , int size)
{
    stack<long>myStack ;
    int i = 0 ;
    long maxArea = INT_MIN ;
    while(i < size)
    {
        while(!myStack.empty() and arr[myStack.top()] >= arr[i])
        {
            int center = myStack.top() ;
            myStack.pop() ;
            long currArea = arr[center]*(myStack.empty() ? i : i - myStack.top() - 1) ;
            maxArea = max(maxArea , currArea) ;
        }
        
        myStack.push(i++) ;
    }
    while(!myStack.empty())
    {
        int center = myStack.top() ;
        myStack.pop() ;
        long currArea = arr[center]*(myStack.empty() ? i : i - myStack.top() - 1) ;
        maxArea = max(maxArea , currArea) ;
    }
    return maxArea ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    int size ;
    	cin >> size ;
    	long arr[size] ;
    	scanArray(arr , size) ;
	    cout << solve(arr , size) << endl ;
	}
	return 0;
}
