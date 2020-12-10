class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) ;
    int helper(vector<vector<int>>& triangle , int level , int pos) ;
};

int Solution :: helper(vector<vector<int>>& triangle , int level , int pos)
{
    if(level + 1 >= triangle.size())
        return triangle[level][pos] ;
    
    return triangle[level][pos] + min(helper(triangle , level + 1 , pos) , 
                                    helper(triangle , level + 1 , pos + 1)) ;
    
}
int Solution :: minimumTotal(vector<vector<int>>& triangle)
{
    return helper(triangle , 0 , 0) ;
}
