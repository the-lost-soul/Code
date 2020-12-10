#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int helper(string str1 , string str2 , int i , int j)
{
    if(i < 0)return j + 1;
    if(j < 0)return i + 1;
    if(str1[i] == str2[j])
    return 1 + helper(str1 , str2 , i - 1 , j - 1) ;
    else
    return 1 + min(helper(str1 , str2 , i - 1, j) ,
               helper(str1 , str2 , i , j - 1) );
}

int main() 
{
    int testcase ;
    cin >> testcase ;
    while(testcase --)
    {
        string str1 , str2 ;
        cin >> str1 >> str2 ;
        int i = str1.length() ;
        int j = str2.length() ;
        cout<<helper(str1 , str2 , i - 1 , j - 1)<<" "<<endl ;
    }
	return 0;
}
