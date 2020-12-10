#include<bits/stdc++.h>
#include<iostream>
using namespace std ;

void scan(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin >> arr[i] ;
}


pair<int , pair<int , int>> solve(int arr[] , int size)
{
    int first , second , third ;
    first = second = third = INT_MIN ;
    for(int i = 0 ; i < size ; i ++)
        if(arr[i] > first)
        {
            third = second ;
            second = first ;
            first = arr[i] ;
        }
        else if(arr[i] > second)
        {
            third = second ;
            second = arr[i] ;
        }
        else if(arr[i] > third)third = arr[i] ;
        
    return make_pair(first , make_pair(second , third)) ;
}


int main()
{
    int testcase ;
    cin >> testcase ;
    while(testcase --)
    {
        int size ;
        cin >> size ;
        int arr[size] ;
        scan(arr , size) ;
        pair<int , pair<int , int> >answer = solve(arr , size) ;
        cout<<answer.first<<" "<<answer.second.first<<" "<<answer.second.second ;
    }
    return 0 ;
}
