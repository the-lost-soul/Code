class Solution 
{
    public:
    bool isValid(string s) ;
};

/* Idea is same as that of a balanced parenthesis problem */

/* The problem can be solved only for strings whose length is 
divisible by 3 */

/* Here we are storing 'a' and 'b' in respective order and if 
we encounter 'c', then we pop from stack if top is 'b' else we 
false and then again we pop from stack if top is 'a' else we
return false.At last if string is valid i.e ba;anced then stack
will be empty otherwise it won't be empty */



bool Solution:: isValid(string s)
{
    int len = s.length() ;
    
    if(len % 3 != 0) return false ;
    
    stack < char > answer ;
    
    for(int i = 0 ; i < len ; i++)
    {
        
        if(answer.empty())
        {
            
            if(s[i] == 'a')answer.push(s[i]) ;
            
        }
        
        else if(s[i] != 'c') answer.push(s[i]) ;
        
        else if(answer.top() == 'b')
        {
            answer.pop() ;
            
            if(!answer.empty() && answer.top() == 'a')
            {
                
                answer.pop();
                
            }
            
            // Without this also code runs fine .
            else return false ;
        }
        
        // Without this also code runs fine .
        else return false ;
    }
    
    return answer.empty() ;
}
