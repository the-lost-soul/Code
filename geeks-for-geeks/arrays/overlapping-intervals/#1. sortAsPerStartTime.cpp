#include<bits/stdc++.h>
#include<iostream>
using namespace std;
struct interval
{
    int start , finish ;
} ;
void scanArray(interval arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        for(int j = 1 ; j <= 2 ; j++)
        {
            if(j == 1)
            {
                cin >> arr[i].start ;
            }
            else cin >> arr[i].finish ;
        }
    }
}

bool comp(interval a , interval b)
{
    if(a.start < b.start)return true ;
    else if(a.start > b.start)return false ;
    return a.finish < b.finish ;
}
void solve(interval arr[] , int size)
{
    // Sort acording to start time .
    sort(arr , arr + size , comp) ;
    int i = 0 , j = 1 ;
    while(j < size)
    {
        if(arr[i].finish >= arr[j].start)
        {
            // Trick was here . 
            arr[i].finish = max(arr[i].finish , arr[j].finish) ;
            arr[i].start = min(arr[i].start , arr[j].start) ;
            arr[j].start = arr[j].finish = -1 ;
            j++ ;
        }
        else
        {
            i = j ;
            j++ ;
        }
    }
}
void printAns(interval arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        if(arr[i].start != -1 and arr[i].finish != -1)
        {
            cout << arr[i].start << " " << arr[i].finish << " " ;
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
    	interval arr[size] ;
    	scanArray(arr , size) ;
	    solve(arr , size) ;
	   printAns(arr , size) ;
	}
	return 0;
}
