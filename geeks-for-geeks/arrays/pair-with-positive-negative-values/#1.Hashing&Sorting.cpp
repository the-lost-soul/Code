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
    unordered_map<int , int>hash = {} ;
    vector<int>negative ;
    bool foundAtLeast1Pair = false ;
    for(int i = 0 ; i < size ; i++)
    {
        if(arr[i] >= 0)hash[arr[i]]++ ;
        else negative.push_back(arr[i]) ;
    }
    sort(negative.begin() , negative.end() , greater<int>()) ;
    for(int i = 0 ; i < negative.size() ; i++)
    {
        if(hash[abs(negative[i])] > 0)
        {
            cout << negative[i] <<" " <<abs(negative[i]) << " " ;
            hash[abs(negative[i])]-- ;
            foundAtLeast1Pair = true ;
        }
    }
    if(!foundAtLeast1Pair)cout<<"0" ;
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
    	int arr[size] ;
    	scanArray(arr , size) ;
	    solve(arr , size) ;
	}
	return 0;
}
