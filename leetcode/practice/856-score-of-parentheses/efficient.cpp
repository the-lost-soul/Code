class Solution {
public:
    int scoreOfParentheses(string s) ;
};

int Solution :: scoreOfParentheses(string s)
{
    int balance =  0 ;
    int score = 0 ;
    for(int i = 0 ; i < s.length() ; i++)
    {
        // Go to next layer .
        if(s[i] == '(')
        {
            balance++ ;
        }
        else
        {
            balance-- ;
            // Calculate the worth of this layer including all
            // the layers inside which current layer is present .
            if(s[i - 1] == '(')
                score += 1<<balance ;
        }
        
    }
    return score ;
}
