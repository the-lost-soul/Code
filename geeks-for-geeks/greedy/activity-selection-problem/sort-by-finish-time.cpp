#include<bits/stdc++.h>
#include<iostream>
using namespace std;
struct activity
{
    int start ;
    int finish ;
    int index ;
} ;
void scanArray(activity arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        cin >> arr[i].start ;
        arr[i].index  = i ;
    }
    for(int i = 0 ; i < size ; i++)
        cin >> arr[i].finish ;
}
bool compare(activity s1 , activity s2)
{
    return s1.finish < s2.finish ;
}
void solve(activity arr[] , int size)
{
    sort(arr , arr + size , compare) ;
    int j = 0 ;
    cout << arr[j].index + 1 << " " ;
    for(int i = 1 ; i < size ; i++)
    {
        if(arr[i].start >= arr[j].finish)
        {
            cout << arr[i].index + 1 << " " ;
            j = i ;
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
	    int size ;
    	cin >> size ;
    	activity arr[size] ;
    	scanArray(arr , size) ;
	    solve(arr , size) ;
	}
	return 0;
}
