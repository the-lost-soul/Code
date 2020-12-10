#include<bits/stdc++.h>
#include <iostream>
using namespace std;

void scanArray(vector<int>&vec , int size)
{
    for(int i = 0 ; i < size ; i++)
    cin >> vec[i] ;
}

void sortK(vector<int>&vec , int size , int k)
{
    // Build a minHeap .
    priority_queue<int , vector<int> , greater<int> > minHeap ;
    int index = 0 ;
    
    /* Push the first k + 1 element to heap .Because the smallest element
     * will be at most k distance away from its target index and hence by pushing 
     * first k+ 1 elements , we will get the smallest element and put it to 
     * it's correct position .
     */
    while(index <= k)
    {
        minHeap.push(vec[index]) ;
        index++ ;
    }

    /* Now one by one pop elements from heap and put it to it's
     * correct position and push the jth element to heap .By the 
     * time we exit from for loop minHeap will contain all the 
     * rest (size - k - 1) element
     */
    index = 0 ;
    for(int j = k + 1 ; j < size ; j++)
    {
        vec[index] = minHeap.top() ;
        minHeap.pop() ;
        minHeap.push(vec[j]) ;
        index ++ ;
    }
    
    // Pop the rest of heap elements and put it to correct position
    // in vector .
    while(!minHeap.empty())
    {
        vec[index] = minHeap.top() ;
        minHeap.pop() ;
        index ++ ;
    }
}

void print(vector<int>&vec , int size)
{
    for(int i = 0 ; i < size ; i++)
    cout<<vec[i]<<" " ;
    cout<<endl ;
}

int main() 
{
	int testcase ;
	cin >> testcase ;
	while(testcase --)
	{
	    int size ;
	    cin >> size ;
	    vector<int>vec(size , 0) ;
	    scanArray(vec , size) ;
	    int k ;
	    cin >> k ;
	    sortK(vec , size , k) ;
	    print(vec , size) ;
	}
	return 0;
}
