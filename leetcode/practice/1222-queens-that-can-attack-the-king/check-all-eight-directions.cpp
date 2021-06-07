class Solution {
public:
     vector<vector<int>>queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king);
};

vector<vector<int>> Solution :: queensAttacktheKing(vector<vector<int>>& queens , vector<int>& king)
{
    int chessBoard[8][8] ;
    memset(chessBoard , -1 , sizeof(chessBoard)) ;
    for(int i = 0 ; i < queens.size() ; i++)
    {
        int queensRow = queens[i][0] , queensCol = queens[i][1] ;
        chessBoard[queensRow][queensCol] = 0 ;
    }
    int kingRow = king[0] , kingCol = king[1] ;
    vector<vector<int>> answer ;
    
    // Move UP
    for(int i = kingRow - 1 ; i >= 0 ; i--)
    {
        if(chessBoard[i][kingCol] == 0)
        {
            answer.push_back({i , kingCol}) ;
            break ;
        }
    }
    
    // Move DOWN .
    for(int i = kingRow + 1 ; i < 8 ; i++)
    {
        if(chessBoard[i][kingCol] == 0)
        {
            answer.push_back({i , kingCol}) ;
            break ;
        }
    }
    
    // Move Left
    for(int i = kingCol - 1 ; i >= 0 ; i--)
    {
        if(chessBoard[kingRow][i] == 0)
        {
            answer.push_back({kingRow , i}) ;
            break ;
        }
    }
    
    // Move Right
    for(int i = kingCol + 1 ; i < 8 ; i++)
    {
        if(chessBoard[kingRow][i] == 0)
        {
            answer.push_back({kingRow , i}) ;
            break ;
        }
    }
    
    
    int tempCol ;
    // Move UPWARDS-LEFT DIAGONALLY
    tempCol = kingCol - 1 ;
    for(int  i = kingRow - 1 ; i >= 0 ; i--)
    {
        if(tempCol >= 0 and chessBoard[i][tempCol] == 0)
        {
            answer.push_back({i , tempCol}) ;
            break ;
        }
        tempCol-- ;
    }
    
    // Move UPWARDS-RIGHT DIAGONALLY
    tempCol = kingCol + 1 ;
    for(int  i = kingRow - 1 ; i >= 0 ; i--)
    {
        if(tempCol < 8 and chessBoard[i][tempCol] == 0)
        {
            answer.push_back({i , tempCol}) ;
            break ;
        }
        tempCol++ ;
    }
    
    // Move DOWNWARDS-LEFT DIAGONALLY
    tempCol = kingCol - 1 ;
    for(int  i = kingRow + 1 ; i < 8 ; i++)
    {
        if(tempCol >= 0 and chessBoard[i][tempCol] == 0)
        {
            answer.push_back({i , tempCol}) ;
            break ;
        }
        tempCol-- ;
    }
    
    // Move DOWNWARDS-RIGHT DIAGONALLY
    tempCol = kingCol + 1 ;
    for(int  i = kingRow + 1 ; i < 8 ; i++)
    {
        if(tempCol < 8 and chessBoard[i][tempCol] == 0)
        {
            answer.push_back({i , tempCol}) ;
            break ;
        }
        tempCol++ ;
    }
    return answer ;
}
