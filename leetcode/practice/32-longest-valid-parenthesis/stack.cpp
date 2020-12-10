class Solution {
public:
    int longestValidParentheses(string s) ;
};

int Solution :: longestValidParentheses(string s)
{
    stack<int>index ;
    index.push(-1) ;
    int len = s.length() ;
    int result = 0 ;
    for(int i = 0 ; i < len ; i++)
    {
        if(s[i] == '(')index.push(i) ;
        else
        {
            index.pop() ;
            if(!index.empty())result = max(result , i - index.top()) ;
            else index.push(i) ;
        }
    }
    return result ;
}
