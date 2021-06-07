class Solution 
{
    int result ;
public:
    int numTilePossibilities(string tiles) ;
    void helper(vector<int>count) ;
};

void Solution :: helper(vector<int>count)
{
    int ans = 0 ;
    for(int i = 0 ; i < 26 ; i++)
    {
        if(count[i])
        {
            count[i]-- ;
            result++ ;
            helper(count) ;
            count[i]++ ;
        }
    }
    
}

int Solution :: numTilePossibilities(string tiles)
{
    vector<int>count(26 , 0) ;
    for(auto ch : tiles)
        count[ch - 'A']++ ;
    helper(count) ;
    return result ;
}
