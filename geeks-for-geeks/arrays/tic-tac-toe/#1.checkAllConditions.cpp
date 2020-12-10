#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool checkWin(char arr[][3] , char player)
{
    for(int i = 0 ; i < 3 ; i++)
    {
        if(arr[0][i] == player and arr[1][i] == player and arr[2][i] == player)
        return true ;
        else if(arr[i][0] == player and arr[i][1] == player and arr[i][2] == player)
        return true ;
        else if(arr[0][0] == player and arr[1][1] == player and arr[2][2] == player)
        return true ;
        else if(arr[0][2] == player and arr[1][1] == player and arr[2][0] == player)
        return true ;
    }
    return false;
}
bool solve(char arr[][3])
{
    int oCount = 0 ;
    int xCount = 0 ;
    for(int i = 0 ; i < 3 ; i++)
    {
        for(int j = 0 ; j < 3 ; j++)
        {
            if(arr[i][j] == 'O')oCount++ ;
            else xCount++ ;
        }
    }
    if(xCount == oCount || xCount == oCount + 1)
    {
        bool xWin = checkWin(arr , 'X') ;
        bool oWin = checkWin(arr , 'O') ;
        if(oWin)
        {
            if(xWin)return false ;
            
            return (xCount == oCount) ;
        }
        
        if(xWin and xCount != oCount + 1)return false ;
        
        return true ;
    }
    return false ;
    
}

int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    char arr[3][3] ;
	    for(int  i = 0 ; i < 3 ; i++)
	    {
	        for(int j = 0 ; j < 3 ; j++)
	        {
	            cin >> arr[i][j] ;
	        }
	    }
	    if(solve(arr))cout<<"Valid" ;
	    else cout<<"Invalid" ;
	    cout<<endl ;
	}
	return 0;
}
