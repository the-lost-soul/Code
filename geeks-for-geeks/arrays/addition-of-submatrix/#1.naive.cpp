#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int ** createMatrix(int **arr , int row , int col)
{
    arr = new int*[row] ;
    for(int i = 0 ; i < row ; i++)
    {
        arr[i] = new int[col] ;
    }
    return arr ;
}
void scanMatrix(int **arr , int row , int col)
{
    for(int i = 0 ; i < row ; i++)
        for(int j = 0 ; j < col ; j++)
            cin >> arr[i][j] ;
}
int solve(int **arr , int row1 , int col1 , int row2 , int col2)
{
    int sum = 0 ;
    // Remember 1-based indexing is used here .
    for(int i = row1 - 1 ; i < row2 ; i++)
        for(int j = col1 - 1 ; j < col2 ; j++)
            sum += arr[i][j] ;
    return sum ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    int row , col ;
    	cin >> row >> col ;
    	int **arr = createMatrix(arr , row , col) ;
    	scanMatrix(arr , row , col) ;
    	int row1 , col1 , row2 , col2 ;
    	cin >> row1 >> col1 >> row2 >> col2 ;
	    cout << solve(arr , row1 , col1 ,row2 , col2) << endl ;
	}
	return 0;
}
