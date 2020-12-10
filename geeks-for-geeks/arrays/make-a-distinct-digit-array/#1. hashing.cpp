#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void scanArray(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin >> arr[i] ;
}
void solve(int arr[] , vector<int>& answer , int size)
{
    // Use set as we need answer in sorted format .
    set<int>hash ;
    for(int i = 0 ; i < size ; i++)
    {
        int ele = arr[i] ;
        while(ele != 0)
        {
            hash.insert(ele%10) ;
            ele /= 10 ;
        }
    }
    for(auto it = hash.begin() ; it != hash.end() ; it++)
    {
        answer.push_back(*it) ;
    }
}
void printAnswer(vector<int>& answer)
{
    for(int i = 0 ; i < answer.size() ; i++)cout << answer[i] << " " ;
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
    	vector<int>answer ;
	    solve(arr , answer , size) ;
	    printAnswer(answer) ;
	}
	return 0;
}
