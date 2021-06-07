class Solution {
public:
    int scoreOfParentheses(string s) ;
};

int Solution :: scoreOfParentheses(string s)
{
    stack<int>myStack ;
    int score = 0 ;
    for(int i = 0 ; i < s.length() ; i++)
    {
        if(s[i] == '(')
        {
            myStack.push(score) ;
            score = 0 ;
        }
        else
        {
            if(score == 0)
            {
                score = myStack.top() + 1 ;
            }
            else
                score = myStack.top() + 2*score ;
            myStack.pop() ;
        }
        
    }
    return score ;
}
