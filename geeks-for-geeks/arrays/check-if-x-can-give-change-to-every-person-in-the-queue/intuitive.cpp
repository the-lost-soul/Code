#include <iostream>
using namespace std;
#include<bits/stdc++.h>

bool solve(vector<int>& arr , int size)
{
    int fivesCount , tensCount ;
    fivesCount = tensCount = 0 ;
    for(int i = 0 ; i < size ; i++)
    {
        if(arr[i] == 5)fivesCount++ ;
        else if(arr[i] == 10)
        {
            if(fivesCount > 0)
            {
                fivesCount-- ;
                tensCount++ ;
            }
            else return false ;
        }
        else
        {
            if(fivesCount > 0 and tensCount > 0)
            {
                fivesCount-- ;
                tensCount-- ;
            }
            else return false ;
        }
    }
    return true ;
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
    if(solve(arr , size))cout << "Possible" << endl ;
    else cout << "Not Possible" << endl ;
    return 0;
}
