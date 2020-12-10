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

int findAnswer(int ** arr , int size , bool **visited , int startRow , int startCol)
{
    queue<pair<int , int>>myQueue ;
    myQueue.push({startRow , startCol}) ;
    int row , col ;
    while(!myQueue.empty())
    {
        row = myQueue.front().first ;
        col = myQueue.front().second ;
        myQueue.pop() ;
        visited[row][col] = true ;
        // Move UP .
        if(isLegal(size , row - 1 , col) and !visited[row - 1][col])
        {
            if(arr[row - 1][col] == 2)return 1 ;
            if(arr[row - 1][col] == 3)
            myQueue.push({row - 1 , col}) ;
            
        }
    
        // Move DOWN .
        if(isLegal(size , row + 1  , col) and !visited[row + 1][col])
        {
            if(arr[row + 1][col] == 2)return 1 ;
            if(arr[row + 1][col] == 3)
            myQueue.push({row + 1 , col}) ;
        }
    
        // Move LEFT .
        if(isLegal(size , row , col - 1) and !visited[row][col - 1])
        {
            if(arr[row][col - 1] == 2)return 1 ;
            if(arr[row][col - 1] == 3)
            myQueue.push({row , col - 1}) ;
        }
        // Move RIGHT .
        if(isLegal(size , row , col + 1) and !visited[row][col + 1])
        {
            if(arr[row][col + 1] == 2)return 1 ;
            if(arr[row][col + 1] == 3)
            myQueue.push({row , col + 1}) ;
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
