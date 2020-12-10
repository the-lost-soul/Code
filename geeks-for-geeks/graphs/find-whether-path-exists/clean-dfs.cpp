#include<iostream>
#include <bits/stdc++.h>
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
    else 
        return false ;
}

int findAnswer(int ** arr , int size , bool **visited , int startRow , int startCol)
{
    stack<pair<int , int>>myStack ;
    myStack.push({startRow , startCol}) ;
    int row , col ;
    
    // Defining directions with [row][col] as origin
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    
    
    while(!myStack.empty())
    {
        row = myStack.top().first ;
        col = myStack.top().second ;
        myStack.pop() ;
        visited[row][col] = true ;
        
        for(int i=0; i<4; i++)
        {
            int x = row + dx[i];
            int y = col + dy[i];
            
            if(isLegal(size,x,y) and !visited[x][y])
            {
                if(arr[x][y]==2) return 1;
                if(arr[x][y]==3) myStack.push({x,y});
            }
        }
    }
    
    
    return 0 ;
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
