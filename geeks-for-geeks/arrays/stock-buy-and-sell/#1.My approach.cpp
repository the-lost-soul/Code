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
    int stockPrice = arr[0] ;
    int buyDay = 0 ;
    int sellDay = 0 ;
    bool noProfit = true ;
    for(int day = 0 ; day < size ;)
    {
        // Get the stock Price of current day .
        stockPrice = arr[day] ;
        // Now , we have to sell the stock .
        sellDay = day ;
        buyDay = day ;
        // Start from next day onwards .
        day = day + 1 ;
        // Iterate till we get a decrease in stock price as compared
        // to the day we buyed the stock and that of yesterday's price .
        while(day < size and arr[day] > arr[day - 1] and arr[day] > stockPrice)
        {
            day++ ;
            // Increment only we the day we want to sold is valid .
            if(sellDay < size - 1)
                sellDay++ ;
            // As we have got one solution so we have atleast one profit.
            noProfit = false ;
        }
        // This is necessary because we may buy a stock say at i'th
        // day and next day only the stock price fell down .So , 
        // basically we won't get profit .
        if(buyDay < sellDay)
            cout<<"("<<buyDay<<" "<<sellDay<<") " ;
    }
    
    if(noProfit == true)
        cout<<"No Profit" ;
    
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
