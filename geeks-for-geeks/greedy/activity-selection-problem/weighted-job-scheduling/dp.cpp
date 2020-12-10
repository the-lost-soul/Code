#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct activity
{
    int start , finish , weight ;
};

bool compare(activity s1 , activity s2)
{
    return (s1.finish < s2.finish) ;
}

int firstNonConflict(activity arr[] , int start)
{
    for(int i = start-1 ; i >= 0 ; i--)
    {
        if(arr[i].finish <= arr[start].start)return i ;
    }
    return -1 ;
}

void solve(activity arr[] , int size)
{
    sort(arr , arr+size , compare) ;
    int profit[size] = {} ;
    profit[0] = arr[0].weight ;
    for(int i = 1 ; i < size ; i++)
    {
        int currProfit = arr[i].weight ;
        int index = firstNonConflict(arr , i) ;
        if(index != -1)currProfit += profit[index] ;
        
        profit[i] = max(currProfit , profit[i-1]) ;
    }
    
    cout << profit[size-1] << endl ;
}
int main() 
{
    int size ;
    cin >> size ;
    activity arr[size] ;
    for(int i = 0 ; i < size ; i++)
    {
        cin >> arr[i].start >> arr[i].finish >> arr[i].weight ;
        // arr[i].index = i ;
    }
    solve(arr , size) ;
    return 0 ;
}
