class Solution
{
public:
    bool isValid(string s)
    {
        stack<char>stk ;
        for(auto ch : s)
        {
            if(ch == '(' or ch == '{' or ch == '[')
                stk.push(ch) ;
            else
            {
                if(stk.empty())
                    return false ;
                if(ch == ')')
                {
                    if(stk.top() == '(')
                        stk.pop() ;
                    else
                        return false ;
                }
                else if(ch == '}')
                {
                    if(stk.top() == '{')
                        stk.pop() ;
                    else
                        return false ;
                }
                else if(ch == ']')
                {
                    if(stk.top() == '[')
                        stk.pop() ;
                    else
                        return false ;
                }
            }
        }
        return stk.empty() ? true : false ;
    }
};
