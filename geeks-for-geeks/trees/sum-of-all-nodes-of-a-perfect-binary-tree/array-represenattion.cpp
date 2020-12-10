#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int solve(int level)
{
    int leafNodes = pow(2 , level - 1) ;
    int totalNodes = pow(2 , level) - 1 ;
    
    // It is array representation of perfect binary tree .
    int tree[totalNodes] ;
    
    int start = totalNodes - leafNodes ;
    // First leaf nodes would be filled with value = 1 , and then
    // increment the value by 1 for each leaf node .
    int value = 1 ;
    int sum = 0 ;
    
    // Start from first leaf nodes till last leaf node .
    for(int i = start ; i < totalNodes ; i++)
    {
        tree[i] = value ;
        sum += tree[i] ;
        value ++ ;
    }
    
    // Now make the parent with the help of children i.e leaf nodes .
    for(int i = start - 1 ; i >= 0 ; i--)
    {
        tree[i] = tree[2*i + 1] + tree[2*i + 2] ;
        sum += tree[i] ;
        
    }
    
    return sum ;
}

int main()
{
    int level ;
    cin >> level ;
    
    if(level > 0)
        cout << "The sum of all nodes is :: " << solve(level) ;
    else cout << "No tree exists ." ;
    
    return 0 ;
}
