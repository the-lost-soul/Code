#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int **createMatrix(int **mat , int row , int col)
{
    mat = new int*[row] ;
    for(int i = 0 ; i < row ; i++)
    {
        mat[i] = new int[col] ;
    }
    return mat ;
}
void printArray(int **mat , int row , int col)
{
    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < col ; j++)
        {
            cout << mat[i][j] << endl ;
        }
    }
}
int **scanArray(int **mat , int row , int col)
{
    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < col ; j++)
        {
            cin >> mat[i][j] ;
        }
    }
    return mat ;
}
int solve(int **mat , int row , int col)
{
    int ansRow = 0 , onesCount = 0 , maxCount = INT_MIN ;
    for(int i = 0 ; i < row ; i++)
    {
        onesCount = 0 ;
        for(int j = 0 ; j < col ; j++)
        {
            if(mat[i][j] == 1)onesCount++ ;
        }
        if(maxCount < onesCount)
        {
            maxCount = onesCount ;
            ansRow = i ;
        }
    }
    return ansRow ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    int row , col ;
    	cin >> row >> col ;
    	int **mat = createMatrix(mat , row , col) ;
    	mat = scanArray(mat , row , col) ;
	    cout << solve(mat , row , col) << endl ;
	}
	return 0;
}
