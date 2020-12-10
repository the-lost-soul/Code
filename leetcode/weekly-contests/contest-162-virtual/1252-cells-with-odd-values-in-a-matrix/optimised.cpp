class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) ;
};

int Solution :: oddCells(int n , int m , vector<vector<int>>& indices)
{
    vector<int>row(n , 0) , col(m , 0) ;
    for(int i = 0 ; i < indices.size() ; i++)
    {
        row[indices[i][0]]++ ;
        col[indices[i][1]]++ ;
    }
    int oddRow = 0 ;
    for(int i = 0 ; i < n ; i++)
        if(row[i]%2 != 0)
            oddRow++ ;
    int oddCol = 0 ;
    for(int i = 0 ; i < m ; i++)
        if(col[i]%2 != 0)
            oddCol++ ;
    
    
    return (n - oddRow)*oddCol + (m - oddCol)*oddRow ;
}
