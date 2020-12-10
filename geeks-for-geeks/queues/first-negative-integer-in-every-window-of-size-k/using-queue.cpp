#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void scanArray(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
    cin >> arr[i] ;
}
void solve(int arr[] , int size , int window)
{
    // It stores all useful elements of current window of
    // size "window" and all of these are negative integers .
    queue<int> q ;
    for(int i = 0 ; i < window ; i++)
    {
        if(arr[i] < 0)q.push(i) ;
    }
    
    // Process rest of the windows .
    for(int i = 0 ; i <= size - window ; i++)
    {
        // If queue is not empty then front element will be
        // the first negative integer of our window .
        if(!q.empty())
        {
            cout<<arr[q.front()]<<" " ;
            // we will pop only if the front is equal to
            // current index , else we won't pop because this
            // front can also be useful for other windows too .
            if(q.front() == i)q.pop() ;
        }
        // If empty then current window does not have any useful elemnt .
        else cout<<"0 " ;
        
        // Check for validity of next window i.e whether (i + window) < size
        // and also check if next window's last element is negative or not .
        // If bot condition satisfies then push that to queue .
        if(i + window < size and arr[i + window] < 0)
        {
            q.push(i + window) ;
        }
        
    }
    cout<<endl ;
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
	    int window ;
	    cin >> window ;
	    solve(arr , size , window) ;
	}
	return 0;
}
