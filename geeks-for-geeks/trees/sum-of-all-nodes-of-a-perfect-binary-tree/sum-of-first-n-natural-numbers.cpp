#include<bits/stdc++.h>
#include <iostream>
using namespace std;

/* The idea here is simple , since we know that leaf nodes contains
 * natural numbers from 1 to n and hence we can calculate the sum of 
 * first n(here n = number of leaf Nodes) to get the equivalent sum 
 * at last level and all upper levels sum will be equal to it only
 * because they are the sum of childrens node only .
 */
int solve(int level)
{
    int leafNodes = pow(2 , level - 1) ;
    
    int sum = leafNodes*(leafNodes + 1)/2 ;
    
    sum *= level ;
    
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
