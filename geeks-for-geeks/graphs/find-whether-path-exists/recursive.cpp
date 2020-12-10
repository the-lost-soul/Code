#include<bits/stdc++.h>
#include<iostream>
using namespace std ;

int ** createMatrix(int ** arr , int size)
{
    arr = new int*[size] ;
    for(int i = 0 ; i < size ; i++)
    {
        arr[i] = new int[size] ;
    }
    return arr ;
}

void scanMatrix(int **arr , int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        for(int j = 0 ; j < size ; j++)
        {
            cin >> arr[i][j] ;
        }
    }
}

pair<int , int>startingIndex(int ** arr , int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        for(int j = 0 ; j < size ; j++)
        {
            if(arr[i][j] == 1)return {i , j} ;
        }
    }
    return {-1 , -1} ;
}

bool isLegal(int size , int row , int col)
{
    if(row >= 0 and row < size and col >= 0 and col < size)
    return true ;
    return false ;
}

int findAnswer(int ** arr , int size , bool **visited , int row , int col)
{
    // If our current move is not legal , then no
    // need to go further .
    if(!isLegal(size , row , col))return 0 ;
    
    // If we have already visited the current cell , 
    // then no need to go ahead .
    if(visited[row][col])return 0 ;
    
    // Mark the current cell visited .
    visited[row][col] = true ;
    
    // If we have reached destination , then return 1 .
    if(arr[row][col] == 2)return 1 ;
    
    // If current cell is a blank wall , then we can't move
    // further ahead .
    if(arr[row][col] == 0)return 0 ;
    
    // If current cell is not a blank cell , then we can't
    // traverse ahead .
    if(!arr[row][col] == 3)return 0 ;
    
    // Since , we have reached here , that means current cell
    // is a valid cell and we can move to other cells through
    // it . So , go for all 4 directions
    return findAnswer(arr , size , visited , row - 1 , col) or
            findAnswer(arr , size , visited , row + 1 , col) or
            findAnswer(arr , size , visited , row , col - 1) or
            findAnswer(arr , size , visited , row , col + 1) ;
    
}

bool ** createBoolMatrix(bool ** visited , int size)
{
    visited = new bool*[size] ;
    for(int i = 0 ; i < size ; i++)
    {
        visited[i] = new bool[size] ;
    }
    return visited ;
}

void scanBoolMatrix(bool ** visited , int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        for(int j = 0 ; j < size ; j++)
        {
            visited[i][j] = false ;
        }
    }
}
int solve(int ** arr , int size)
{
    // Get the index from where we have to start the journey .
    pair<int , int>index = startingIndex(arr , size) ;
    if(index.first == -1 and index.second == -1)return 0 ;
    
    int startRow = index.first ;
    int startCol = index.second ;
    
    bool ** visited = createBoolMatrix(visited , size) ;
    scanBoolMatrix(visited , size) ;
    return findAnswer(arr , size , visited , startRow , startCol) ;
    
}

int main()
{
    int testcase ;
    cin >> testcase ;
    while(testcase --)
    {
        int size ;
        cin >> size ;
        int ** arr ;
        arr = createMatrix(arr , size) ;
        scanMatrix(arr , size) ;
        cout<<solve(arr , size)<<endl ;
    }
    return 0 ;
}
