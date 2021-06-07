class Solution {
public:
    vector<string> generateParenthesis(int n) ;
    void helper(int n , string s , int openPCount , int closePCount , vector<string>& ans) ;
};

void Solution :: helper(int n , string s , int open , int close , vector<string>&ans)
{
    if(s.length() == 2*n)
    {
        ans.push_back(s) ;
        return ;
    }
    
    if(open < n)
    {
        helper(n , s + '(', open + 1 , close , ans) ;
    }
    if(close < open)
    {
        helper(n , s + ')', open , close + 1  , ans) ;
    }
}
vector<string> Solution :: generateParenthesis(int n)
{
    vector<string>ans ;
    string s = "" ;
    int openParCount = 0 , closeParCount = 0 ;
    helper(n , s , openParCount , closeParCount , ans) ;
    return ans ;
}
