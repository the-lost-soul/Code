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
        if(a.second > b.second)return true ;
        else if(a.second < b.second)return false ;
        return a.first < b.first ;
    }
} ;
void solve(int arr[] , int size , int k)
{
    // Getting the top "k" elements are done using it .
    set<pairs , comp>hash ;
    // It is just to give us the frequency of any element which
    // be required ahead when searching for a pair in set .
    unordered_map<int , int>helper ;
    for(int i = 0 ; i < size ; i++)
    {
        // If current element has arrived first time .
        if(helper.find(arr[i]) == helper.end())
        {
            helper[arr[i]]++ ;
            hash.insert({arr[i] , 1}) ;
        }
        else
        {
            // Get the details i.e (ele , freq) of the current element 
            pairs details = {arr[i] , helper[arr[i]]} ;
            // Get the iterator pointing to this element .
            set<pairs> :: iterator itr = hash.find(details) ;
            // Delete this element .
            hash.erase(itr) ;
            // Increment the frequency of the current element .
            helper[arr[i]]++ ;
            // Insert it again to set .
            hash.insert({arr[i] , helper[arr[i]]}) ;
        }
        
        // Get the top k elements from set .
        int l = 0 ;
        set<pairs> :: iterator it = hash.begin() ;
        while(it != hash.end() and l < k)
        {
            cout <<it->first << " " ;
            it++ ;
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
