#include<bits/stdc++.h>
#include <iostream>
using namespace std;

void scan(int arr[] , int nodes)
{
    for(int i = 0 ; i < nodes ; i++)
    {
        cin >> arr[i] ;
    }
}

void solve(int arr[] , int start , int nodes)
{
    if(start == nodes)
    {
        cout<<arr[start]<<" " ;
        return ;
    }
    else if(start > nodes)return ;
    int i = start + 1;
    // find the first node greater than the current node .
    while(arr[start] > arr[i] and i <= nodes)
        i++ ;
    solve(arr , start + 1 , i - 1) ;
    solve(arr , i , nodes) ;
    cout<<arr[start]<<" " ;
}

int main() 
{
    int testcase ;
    cin >> testcase ;
    while(testcase --)
    {
        int nodes ;
        cin >> nodes ;
        int arr[nodes] ;
        scan(arr , nodes) ;
        solve(arr , 0 , nodes - 1) ;
        cout<<endl ;
    }
	return 0;
}
