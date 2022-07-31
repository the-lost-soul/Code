class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) ;
};


string Solution :: tictactoe(vector<vector<int>>& moves)
{
    char board[3][3] ;
    for(int i = 0 ; i < 3 ; i++)
    {
        for(int j = 0 ; j < 3 ; j++)
        {
            board[i][j] = '\0' ;
        }
    }
    int aTurn = true ;
    for(int i = 0 ; i < moves.size() ; i++)
    {
        int row = moves[i][0] , col = moves[i][1] ;
        if(aTurn)
        {
            board[row][col] = 'x' ;
            aTurn = false ;
        }
        else
        {
            board[row][col] = 'o' ;
            aTurn = true ;
        }
    }
    
    // First Row
    if(board[0][0] == board[0][1] and board[0][1] == board[0][2])
    {
        if(board[0][0] != '\0')return board[0][0] == 'x' ? "A" : "B" ;
    }
    // Second Row
    if(board[1][0] == board[1][1] and board[1][1] == board[1][2])
    {
        if(board[1][0] != '\0')return board[1][0] == 'x' ? "A" : "B" ;
    }
    // Last Row
    if(board[2][0] == board[2][1] and board[2][1] == board[2][2])
    {
        if(board[2][0] != '\0')return board[2][0] == 'x' ? "A" : "B" ;
    }
    
    // First Col
    if(board[0][0] == board[1][0] and board[1][0] == board[2][0])
    {
        if(board[0][0] != '\0')return board[0][0] == 'x' ? "A" : "B" ;
    }
    // Second Col
    if(board[0][1] == board[1][1] and board[1][1] == board[2][1])
    {
        if(board[0][1] != '\0')return board[0][1] == 'x' ? "A" : "B" ;
    }
    // Last Col
    if(board[0][2] == board[1][2] and board[1][2] == board[2][2])
    {
        if(board[0][2] != '\0')return board[0][2] == 'x' ? "A" : "B" ;
    }
    
    
    // Diagonal b/w first row and col
    if(board[0][0] == board[1][1] and board[1][1] == board[2][2])
    {
        if(board[0][0] != '\0')return board[0][0] == 'x' ? "A" : "B" ;
    }
    
    // Diagonal b/w last row and col
    if(board[0][2] == board[1][1] and board[1][1] == board[2][0])
    {
        if(board[0][2] != '\0')return board[0][2] == 'x' ? "A" : "B" ;
    }

    if(moves.size() == 9)return "Draw" ;
    return "Pending" ;


}
