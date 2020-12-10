#include <iostream>
using namespace std;
#include<bits/stdc++.h>

vector<int> emptyQueue(queue<int>q0 , queue<int>q1 , queue<int> q2)
{
    vector<int>ans ;
    while(!q0.empty())
    {
        int ele = q0.front() ;
        q0.pop() ;
        ans.push_back(ele) ;
    }
    
    while(!q1.empty())
    {
        int ele = q1.front() ;
        q1.pop() ;
        ans.push_back(ele) ;
    }
    
    while(!q2.empty())
    {
        int ele = q2.front() ;
        q2.pop() ;
        ans.push_back(ele) ;
    }
    return ans ;
}
void countingSort(vector<int>&arr , int size)
{
    vector<int>count(10 , 0) ;
    for(int i = 0 ; i < size ; i++)count[arr[i]]++ ;
    
    int index = 0 ;
    for(int i = 0 ; i < 10 ; i++)
    {
        int ele = count[i] ;
        while(ele-- > 0)
        {
            arr[index++] = i ;
        }
    }
}
vector<int> solve(vector<int>& arr , int size)
{
    countingSort(arr , size) ;
    queue<int>q0 , q1 , q2 ;
    int sum = 0 ;
    for(int i = 0 ; i < size ; i++)
    {
        sum += arr[i] ;
        if(arr[i]%3 == 0)q0.push(arr[i]) ;
        else if(arr[i]%3 == 1)q1.push(arr[i]) ;
        else q2.push(arr[i]) ;
    }
   
    if(sum%3 == 1)
    {
        if(!q1.empty())q1.pop() ;
        else
        {
            if(q2.size() >= 2)
            {
                q2.pop() ;
                q2.pop() ;
            }
            else return {} ;
        }
    }
    else if(sum%3 == 2)
    {
        if(!q2.empty())q2.pop() ;
        else
        {
            if(q1.size() >= 2)
            {
                q1.pop() ;
                q1.pop() ;
            }
            else return {} ;
        }
    }
    
    vector<int>ans = emptyQueue(q0 , q1 , q2) ;
    countingSort(ans , size) ;
    reverse(begin(ans) , end(ans)) ;
    return ans ;
}
void print(vector<int>& arr)
{
    for(int i = 0 ; i < arr.size() ; i++)cout << arr[i] << endl ;
    cout << endl ;
}
int main() 
{
    int size ;
    cin >> size ;
    vector<int> arr(size) ;
    for(int i = 0 ; i < size ; i++)
    {
        cin >> arr[i] ;
    }
    vector<int> ans = solve(arr , size) ;
    if(ans.size() == 0)cout << "Not Possible" << endl ;
    else print(ans) ;
    return 0;
}
