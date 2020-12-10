#include <iostream>
using namespace std;
#include<bits/stdc++.h>

bool solve(queue<int> popQ , int size)
{
    queue<int>pushQ ;
    stack<int>stk ;
    int expected = 1 ;
    while(!popQ.empty())
    {
        int curr = popQ.front() ;
        popQ.pop() ;
        if(curr == expected)
        {
            pushQ.push(curr) ;
            expected++ ;
        }
        else
        {
            if(stk.empty())stk.push(curr) ;
            else if(!stk.empty() and stk.top() < curr)return false ;
            else stk.push(curr) ;
        }
        
        while(!stk.empty() and stk.top() == expected)
        {
            pushQ.push(stk.top()) ;
            stk.pop() ;
            expected++ ;
        }
    }
    
    if(expected - 1 == size and stk.empty())return true ;
    return false ;
}

int main() 
{
    int size ;
    cin >> size ;
    queue<int>popQ ;
    for(int i = 0 ; i < size ; i++)
    {
        int ele ; 
        cin >> ele ;
        popQ.push(ele) ;
    }
    if(solve(popQ , size)) cout << "Queue can be sorted ." << endl ;
    else cout << "Queue can't be sorted ." << endl ;
	return 0;
}
