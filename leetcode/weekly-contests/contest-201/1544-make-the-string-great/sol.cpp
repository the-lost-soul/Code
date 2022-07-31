class Solution
{
public:
    string makeGood(string s)
    {
        if(s.length() <= 1)
            return s ;
        int i = 0 , j = 1 ;

        stack<int>stk ;
        while(i < j and i < s.length() - 1)
        {
            if(isupper(s[i]) and islower(s[j]) and tolower(s[i]) == s[j]
                or islower(s[i]) and isupper(s[j]) and tolower(s[j]) == s[i])
            {
                s[i] = '\n' ;
                s[j] = '\n' ;
                if(!stk.empty())
                {
                    i = stk.top() ;
                    stk.pop() ;
                    j++ ;
                }
                else
                {
                    i = j + 1 ;
                    j = j + 2 ;
                }
            }
            else
            {
                stk.push(i) ;
                i = j ;
                j = j + 1 ;
            }
        }
        string ans = "" ;
        for(auto ele : s)
            if(ele != '\n')
                ans += ele ;
        return ans ;
        
    }
};
