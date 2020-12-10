#include<bits/stdc++.h>
#include<iostream>
using namespace std;
/* Since , the matrix is sorted so we start counting ones from last element
 * of first column . If the current field of matrix is 1 then we set the
 * ansRow = currRow i.e i and we decrement j i.e column WHEREAS
 * If current field of matrix is 0 , then we simply move ahead one row .
 * Now in the new row we start from the same column where the field entry
 * was 0 for previous row and if we get a 1 here then we set ansRow = currRow(i)
 * as per algorithm , because number of 1's in the currRow will be at least one  
 * more than that of previous row . 
 */
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
    int ansRow = 0 , i = 0 , j = col - 1 ;
    while(i < row and j >= 0)
    {
        if(mat[i][j] == 1)
        {
            ansRow = i ;
            j-- ;
        }
        else
        {
            i++ ;
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
