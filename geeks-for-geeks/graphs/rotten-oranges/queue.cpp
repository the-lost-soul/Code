#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

bool isLegal(int posRow, int posCol, int row, int col)
{
    if(posRow>=0 && posRow<row && posCol>=0 && posCol<col) return true;
    return false;
}
int BFS(int rotten[MAX][MAX], int row, int col)
{
    
    
    int visited[row][col];
    memset(visited,0,sizeof(visited));
    queue<pair<int,int>>rottenIndex;
    for(int i=0; i<row; i++)
    
        for(int j=0; j<col; j++)
        
            if(rotten[i][j]==2)
            
                rottenIndex.push(make_pair(i,j));
                // cout<<i<<" "<<j<<endl;
            
        
    
    
    // Time taken to rot all oranges
    // int (_time)=0;// This was wrong
    
    // initialize time from -1 as first delimetre
    // is misleading because the first set of oranges
    // will take no time to rot
    int _time=-1;
    
    
    // it is a delimetre for time 
    // if it is reached then we increment count
    // else we do not increment time until we
    // reach the delimetre
    rottenIndex.push(make_pair(-1,-1));
    
    while(!rottenIndex.empty())
    
        // first--> denotes ith row
        int first=(rottenIndex.front()).first;
        
        // Second--> denotes jth column
        int second=(rottenIndex.front()).second;
        // cout<<first<<" "<<second<<endl;
        // This means ith row and jth column is visited
        // visited[first][second]=1;
        // POP the index
        rottenIndex.pop();
        // cout<<(rottenIndex.front()).first<<" "<<(rottenIndex.front()).second<<endl;
        // check legality of the move 
        // If true then ,Moves up
        if(isLegal(first-1,second,row,col))
        
            if(rotten[first-1][second]==1 && !visited[first-1][second])
            
                // Make the fresh orange rooten
                // and enqueue the newly rotten
                // orange
                rotten[first-1][second]=2;
                visited[first-1][second]=1;
                rottenIndex.push(make_pair(first-1,second));
                // cout<<"UP"<<" "<<first-1<<" "<<second<<" "<<rotten[first-1][second]<<endl;
            
        
        // check legality of the move 
        // If true then ,Moves down
        if(isLegal(first+1,second,row,col))
        
            if(rotten[first+1][second]==1 && rotten[first+1][second])
            
                rotten[first+1][second]=2;
                visited[first+1][second]=1;
                rottenIndex.push(make_pair(first+1,second));
                // cout<<"DOWN"<<" "<<first+1<<" "<<second<<" "<<rotten[first+1][second]<<endl;
            
            
        
        // check legality of the move 
        // If true then ,Moves left
        if(isLegal(first,second-1,row,col))
        
            if(rotten[first][second-1]==1 && !visited[first][second-1])
            
                
                rotten[first][second-1]=2;
                visited[first][second-1]=1;
                rottenIndex.push(make_pair(first,second-1));
                // cout<<"LEFT"<<" "<<first<<" "<<second-1<<" "<<rotten[first][second-1]<<endl;
            
        
        // check legality of the move 
        // If true then ,Moves right
        if(isLegal(first,second+1,row,col))
        
            if(rotten[first][second+1]==1 && !visited[first][second+1])
            
                rotten[first][second+1]=2;
                visited[first][second+1]=1;
                rottenIndex.push(make_pair(first,second+1));
                // cout<<"RIGHT"<<" "<<first<<" "<<second+1<<" "<<rotten[first][second+1]<<endl;
            
            
        
        // If we reach the delimetre then we pop that delimetre
        // and pushes it to front queue again and also we 
        // increment time
        if((rottenIndex.front()).first==-1 && (rottenIndex.front()).second==-1)
        
            rottenIndex.pop();
            rottenIndex.push(make_pair(-1,-1));
            (_time)++;
        
    
    
    for(int i=0; i<row; i++)
    
        for(int j=0; j<col; j++)
        
            // If we get any fresh oranges then
            // we are not able to rot all oranfges
            // so return -1
            if(rotten[i][j]==1)return -1;
        
    
    return (_time);
    
    
}
int main() 
{
    //code
    int testcases;
    scanf("%d",&testcases);
    while(testcases--)
    {
        int row,col;
        // int rotten[row][col]={};
        scanf("%d%d",&row,&col);
        int rotten[MAX][MAX];
        memset(rotten,0,sizeof(rotten));
        
       // int **rotten;
       // rotten = createMatrix(rotten,row,col);
        
        // Scan the array
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                scanf("%d",&rotten[i][j]);
            }
        }
        // Do BFS on that 2-D array and print time
        printf("%d\n",BFS(rotten,row,col));
    }
    return 0;
}




// BHAIYYA’s CODE


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int ROW;
int COL;

/* Utility function to check if the index is in bounds or not */
bool legal(int row, int col)
{
    // Use this template instead
    return (row>=0 && row<ROW && col>=0 && col<COL);
}

/* This function visits the cell (i,j) given the constraints */
void visitTheCell(int i, int j, vector<vector<int>> &mat, vector<vector<bool>> &visited, queue<pair<int,int>> &myQueue)
{
    // In bounds and not visited and should contain fresh oranges
    if(legal(i,j) && !visited[i][j] && mat[i][j]==1)
    
        // Push it on the queue to rot other oranges, and visit it
        myQueue.push(make_pair(i,j));
        visited[i][j] = true;
    
}

int rottenOranges(vector<vector<int>> &mat)
{
    // Set the delimiter to record time
    auto deLimiter = make_pair(-1,-1);
    
    // Set the queue to store vertices
    queue<pair<int,int>> myQueue;
    
    // Create the visited matrix
    vector<vector<bool>> visited;
    
    // Resize the viisted matrix and set it to false
    visited.resize(ROW);
    for(auto &row_vec : visited)
        row_vec.resize(COL);
    
    // Traverse the matrix and store the cells with rotten oranges
    for(int i=0; i<ROW; i++)
        for(int j=0; j<COL; j++)
            if(mat[i][j] == 2) myQueue.push(make_pair(i,j));
            
    // Now that all the rottten oranges are stored, Push the deLimiter
    myQueue.push(deLimiter);
    
    // Create the counter from -1 as the first deLimiter is misleading, the first set of oranges
    // take no time to rot as they are already rotted
    int __time=-1;
    
    // Apply BFS
    while(!myQueue.empty())
    
        while(myQueue.front()!=deLimiter)
        
            // Extract the current element and rot all the neighbours
            auto current = myQueue.front();
            myQueue.pop();
            
            // Store the location of cells
            int i, j;
            i = current.first;
            j = current.second;
            
            // Visit all the neighbours
            
            // Up 
            visitTheCell(i-1,j,mat,visited,myQueue);
            
            // Down
            visitTheCell(i+1,j,mat,visited,myQueue);
            
            // Left
            visitTheCell(i,j-1,mat,visited,myQueue);
            
            // Right
            visitTheCell(i,j+1,mat,visited,myQueue);
        
        
        // So now we have a deLimiter, pop it and see if the queue is empty
        // If it is not, insert a new deLimiter
        
        myQueue.pop();
        
        // Increase the time as delimiter has been popped 
        __time++;
        
        // Check if deLimiter has to be pushed
        if(!myQueue.empty()) myQueue.push(deLimiter);
    
    
    bool isFreshOrangeLeft = false;
    
    // Traverse and check if all the oranges have been rotted or not
    for(int i=0; i<ROW; i++)
        for(int j=0; j<COL; j++)
            if(mat[i][j]==1 && !visited[i][j]) isFreshOrangeLeft = true;
    
    if(isFreshOrangeLeft) return -1;
    else return __time;
}

void scanVector(vector<vector<int>> &mat)
{
    for(int i=0; i<ROW; i++)
        for(int j=0; j<COL; j++)
             cin >> mat[i][j];
}

int main() {
    int t;
    cin >> t;
    for(int i=0; i<t; i++)
    {
        cin >> ROW; cin >> COL;
        vector<vector<int>> mat;
        
        mat.resize(ROW);
        for(auto &row_vec :mat)
            row_vec.resize(COL);
            
        scanVector(mat);
        cout << rottenOranges(mat) << endl;
    }
    return 0;
}


