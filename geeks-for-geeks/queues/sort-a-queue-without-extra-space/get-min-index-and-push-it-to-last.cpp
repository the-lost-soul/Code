#include <iostream>
using namespace std;
#include<bits/stdc++.h>

void sortQ(queue<int>& q , int index)
{
    int rear , n = q.size() ;
    for(int i = 0 ; i < n ; i++)
    {
        int curr = q.front() ;
        q.pop() ;
        if(i != index)
        {
            q.push(curr) ;
        }
        else rear = curr ;
    }
    q.push(rear) ;
    // queue<int> temp = q ;
    // while(!temp.empty())
    // {
    //     cout << temp.front() << " " ;
    //     temp.pop() ;
    // }
    // cout << endl ;
}
int getIndex(queue<int> q , int till)
{
    int minEle = INT_MAX ;
    int minIndex = 0 ;
    int n = q.size() ;
    for(int i = 0 ; i < n ; i++)
    {
        int curr = q.front() ;
        q.pop() ;
        if(curr <= minEle and i < till)
        {
            minIndex = i ;
            minEle = curr ;
        }
        q.push(curr) ;
    }
    return minIndex ;
}

void solve(queue<int>&q , int size)
{
   for(int i = 0 ; i < size ; i++)
   {
       int index = getIndex(q , size - i) ;
       sortQ(q , index) ;
   }
}
void print(queue<int> q)
{
    while(!q.empty())
    {
        cout << q.front() << " " ;
        q.pop() ;
    }
    cout << endl ;
}
int main() 
{
    int size ;
    cin >> size ;
    queue<int>myq ;
    for(int i = 0 ; i < size ; i++)
    {
        int ele ; 
        cin >> ele ;
        myq.push(ele) ;
    }
    solve(myq , size) ;
    print(myq) ;
    return 0;
}
