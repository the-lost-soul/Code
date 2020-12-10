#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef struct
{
    int buyDay ;
    int sellDay ;
}interval ;
void scanArray(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
    cin >> arr[i] ;
}
void solve(int arr[] , int n)
{
    int i = 0 ;
    int stockCount = 0 ;
    interval details[n/2] ;
    while(i < n - 1)
    {
        // Find the local minima to buy the stock on that day.
        // Note the limit is (n - 2) because we are comparing
        // present day stock to next day stock .
        while((i < n - 1) and (arr[i] >= arr[i + 1]))i++ ;
        
        // If we reach end , then there is no solution possible .
        if(i == n - 1)break ;
        
        details[stockCount].buyDay = i++ ;
        
        // Find the local maxima to sell the stack on that day .
        // Note that limit is (n - 1) because we are comparing
        // present day stock with previous day stock .
        while((i < n) and (arr[i] >= arr[i - 1]))i++ ;
        
        details[stockCount].sellDay = i - 1 ;
        
        stockCount++ ;
    }
    if(stockCount == 0)cout<<"No Profit" ;
    else
    {
        for(int i = 0 ; i < stockCount ; i++)
        {
            cout<<"("<<details[i].buyDay<<" "<<details[i].sellDay<<") " ;
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
	    solve(arr , size) ;
	}
	return 0;
}
