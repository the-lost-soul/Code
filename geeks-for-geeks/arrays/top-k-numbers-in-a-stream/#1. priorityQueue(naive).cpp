#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef pair<int , int> pairs ;
void scanArray(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin >> arr[i] ;
}
class comp
{
    public :
    bool operator()(pairs a , pairs b)
    {
        if(a.second < b.second)return true ;
        else if(a.second > b.second)return false ;
        return a.first > b.first ;
    }
} ;
void solve(int arr[] , int size , int k)
{
    unordered_map<int , int>hash ;
    for(int i = 0 ; i < size ; i++)
    {
        hash[arr[i]]++ ;
        int l = 0 ;
        priority_queue<pairs , vector<pairs> , comp>minHeap(hash.begin() , hash.end()) ;
        while(!minHeap.empty() and l < k)
        {
            pairs ele = minHeap.top() ;
            cout <<ele.first << " " ;
            minHeap.pop() ;
            l++ ;
        }
    }
    cout << endl ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    int size , k ;
    	cin >> size >> k ;
    	int arr[size] ;
    	scanArray(arr , size) ;
	    solve(arr , size , k) ;
	}
	return 0 ;
}
