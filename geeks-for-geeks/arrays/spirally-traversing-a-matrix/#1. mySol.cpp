#include<bits/stdc++.h>
#include <iostream>
using namespace std;
int ** createMatrix(int ** mat , int row , int col)
{
    mat = new int*[row] ;
    for(int i = 0 ; i < row ; i++)
    {
        mat[i] = new int[col] ;
    }
    return mat ;
}

void scanMatrix(int **mat , int row , int col)
{
    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < col ; j++)
        {
            cin >> mat[i][j] ;
        }
    }
}

void solve(int ** mat , int row , int col)
{
    int firstRow = 0 , lastRow = row - 1 ;
    int firstCol = 0 , lastCol = col - 1 ;
    
    while(firstRow <= lastRow and firstCol <= lastCol)
    {
        for(int i = firstCol ; i <= lastCol ; i++)
            cout<<mat[firstRow][i]<<" " ;
        firstRow ++ ;
        
        for(int i = firstRow ; i <= lastRow ; i++)
            cout<<mat[i][lastCol]<<" " ;
        lastCol -- ;
        
        if(lastRow >= firstRow)
        {
            for(int i = lastCol ; i >= firstCol ; i--)
                cout<<mat[lastRow][i]<<" " ;
        }
        lastRow -- ;
        
        if(lastCol >= firstCol)
        {
            for(int i = lastRow ; i >= firstRow ; i--)
                cout<<mat[i][firstCol]<<" " ;
        }
        firstCol ++ ;
    }
    cout<<endl ;
}
void print(int ** mat , int row , int col)
{
    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < col ; j++)
        {
            cout<<mat[i][j]<<" " ;
        }
    }
}

int main() 
{
    int testcase ;
    cin >> testcase ;
    while(testcase --)
    {
        int row , col ;
        cin >> row >> col ;
        int ** mat ;
        mat = createMatrix(mat , row , col) ;
        scanMatrix(mat , row , col) ;
        solve(mat , row , col) ;
        // print(mat , row , col) ;
    }
	return 0;
}
