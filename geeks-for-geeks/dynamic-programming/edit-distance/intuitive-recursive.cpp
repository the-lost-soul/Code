#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int min(int insert , int remov , int del)
{
    return min(insert , min(remov , del)) ;
}

int solve(string source , string target , int sourceLength , int targetLength)
{
    if(sourceLength == 0)return targetLength ;
    if(targetLength == 0)return sourceLength ;
    
    if(source[sourceLength - 1] == target[targetLength - 1])
    return solve(source , target , sourceLength - 1 , targetLength - 1) ;
    
    else return 1 + min(solve(source , target , sourceLength , targetLength - 1) ,
                        solve(source , target , sourceLength - 1 , targetLength) ,
                        solve(source , target , sourceLength - 1 , targetLength - 1)) ;
    
    
    
}

int main() 
{
    int testcase ;
    cin >> testcase ;
    string source ;
    int sourceLength ;
    string target ;
    int targetLength ;
    while(testcase --)
    {
        cin >> sourceLength ;
        cin >> targetLength ;
        cin >> source ;
        cin >> target ;
        cout << solve(source , target , sourceLength , targetLength) << endl ;
    }
	return 0;
}
