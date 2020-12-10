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
    int ans = 0 ;
    for(int i = 0 ; i < n ; i++)
    {
        int sum = row[i] ;
        for(int j = 0 ; j < m ; j++)
        {
            if((sum + col[j])%2 != 0)ans++ ;
        }
    }
    return ans ;
}
