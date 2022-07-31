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
    
    for(int i = 0 ; i < 3 ; i++)
    {
        // Checks all 3 Rows .
        if(board[i][0] == board[i][1] and board[i][1] == board[i][2])
        {
            if(board[i][0] != '\0')return board[i][0] == 'x' ? "A" : "B" ;
        }
        // Checks all 3 columns .
        if(board[0][i] == board[1][i] and board[1][i] == board[2][i])
        {
            if(board[0][i] != '\0')return board[0][i] == 'x' ? "A" : "B" ;
        }
        
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

    return (moves.size() == 9) ? "Draw" : "Pending" ;


}
