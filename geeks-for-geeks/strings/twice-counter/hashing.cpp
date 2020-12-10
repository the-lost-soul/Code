#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void scanArray(vector<string>&vec , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin >> vec[i] ;
}
int solve(vector<string>&vec , int size)
{
   
    unordered_map<string , int>hash ;
    for(int i = 0 ; i < size ; i++)
    {
        hash[vec[i]]++ ;
    }
    int count = 0 ;
    for(auto ele : hash)
    {
        if(ele.second == 2)count ++ ;
    }
    return count ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    int size ;
    	cin >> size ;
    	vector<string>vec(size) ;
    	scanArray(vec , size) ;
	    cout << solve(vec , size) << endl ;
	}
	return 0;
}
