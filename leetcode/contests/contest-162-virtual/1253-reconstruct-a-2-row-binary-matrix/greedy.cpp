class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) ;
};

vector<vector<int>> Solution :: reconstructMatrix(int upper , int lower , vector<int>& colsum)
{
    int sum = accumulate(colsum.begin() , colsum.end() , 0) ;
    if(upper + lower != sum)return {} ;
    int col = colsum.size() ;
    vector<vector<int>>ans(2 , vector<int>(col , 0)) ;
    for(int i = 0 ; i < col ; i++)
    {
        if(colsum[i] == 2)
        {
            if(upper > 0 and lower > 0)
            {
                ans[0][i] = ans[1][i] = 1 ;
                upper-- ;
                lower-- ;
            }
            else return {} ;
        }
    }
    
    for(int i = 0 ; i < col ; i++)
    {
        if(colsum[i] == 1)
        {
            if(upper > 0)
            {
                ans[0][i] = 1 ;
                upper-- ;
            }
            else if(lower > 0)
            {
                ans[1][i] = 1 ;
                lower-- ;
            }
            else return {} ;
        }
    }
    return ans ;
}
