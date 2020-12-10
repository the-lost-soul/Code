/* Here the concept used is that we store the original
 * matrix in another matrix say duplicate and then we
 * go on ahead to transform i.e to rotate the matrix to
 * 90 degree .
 * Here the main concept is to find how for every index
 * (i , j) we can get the desired element from the
 * duplicate array to be assigned to original array .So
 * this can be done by understanding the fact that for every
 * ith row the (row - i - 1)th column is needed , and this 
 * completes whole algorithm .
 */
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

void scanMatrix(int ** ques , int row , int col)
{
    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < col ; j++)
        {
            cin >> ques[i][j] ;
        }
    }
}

void copyMatrix(int ** ques , int ** duplicate , int row , int col)
{
    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < col ; j++)
        {
            duplicate[i][j] = ques[i][j] ;
        }
    }
}

void rotate(int ** ques , int ** duplicate , int row , int col)
{
    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < col ; j++)
        {
            ques[i][j] = duplicate[j][row - i - 1] ;
        }
    }
}

void solve(int ** ques , int row , int col)
{
    int ** duplicate ;
    duplicate = createMatrix(duplicate , row , col) ;
    copyMatrix(ques , duplicate , row , col) ;
    rotate(ques , duplicate , row , col) ;
}

void print(int ** ques , int row , int col)
{
    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < col ; j++)
        {
            cout<<ques[i][j]<<" " ;
        }
    }
    cout<<endl ;
}

int main() 
{
    int testcase ;
    cin >> testcase ;
    while(testcase --)
    {
        int size ;
        cin >> size ;
        int row , col ;
        row = col = size ;
        int ** ques ;
        ques = createMatrix(ques , row , col) ;
        scanMatrix(ques , row , col) ;
        solve(ques , row , col) ;
        print(ques , row , col) ;
    }
	return 0;
}
