#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int ** createMatrix(int ** mat , int row , int col)
{
    mat = new int*[row] ;
    for(int i = 0 ; i < row ; i++)
        mat[i] = new int[col] ;
    return mat ;
    
}

void scanMatrix(int ** ques , int row , int col)
{
    for(int i = 0 ; i < row ; i++)
        for(int j = 0 ; j < col ; j++)
            cin >> ques[i][j] ;
}
void rotate(int ** ques , int row , int col)
{
    int temp = 0 ;
    for(int ring = 0 ; ring < row/2 ; ring ++)
        {
            for(int i = ring ; i < row - ring - 1 ; i ++)
            {
                temp = ques[ring][i] ;
                ques[ring][i] = ques[i][row - ring - 1] ;
                ques[i][row - ring - 1] = ques[row - ring - 1][row - i - 1] ;
                ques[row - ring - 1][row - i - 1] = ques[row - i - 1][ring] ;
                ques[row - i - 1][ring] = temp ;
            }
        }
}

void print(int ** ques , int row , int col)
{
    for(int i = 0 ; i < row ; i++)
        for(int j = 0 ; j < col ; j++)
            cout<<ques[i][j]<<" " ;
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
        rotate(ques , row , col) ;
        print(ques , row , col) ;
    }
	return 0;
}
