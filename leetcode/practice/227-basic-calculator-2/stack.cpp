class Solution {
public:
    int calculate(string s)
    {
       stack<int> num ;
       char sign = '+' ;
       int currentNum = 0 ;
       for(int i = 0 ; i < s.size() ; i++)
       {
           char ch = s[i] ;
           if(isdigit(ch)) currentNum = currentNum*10 + (ch - '0') ;
           
           if(!isdigit(ch) and !isspace(ch) or (i == s.size() - 1))
           {
               if(sign == '-') num.push(-currentNum) ;
               else if(sign == '+') num.push(currentNum) ;
               else
               {
                   int evaluate ;
                   if(sign == '*')
                   {
                       evaluate = num.top()*currentNum ;
                   }
                   else evaluate = num.top()/currentNum ;

                   num.pop() ;
                   num.push(evaluate) ;
               }
               sign = ch ;
               currentNum = 0 ;
           }

       }

       int ans = 0 ;
       while(!num.empty())
       {
           ans += num.top() ;
           num.pop() ;
       }
       return ans ;
    }
};
;
