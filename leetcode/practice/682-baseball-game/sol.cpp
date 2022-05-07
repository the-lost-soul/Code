class Solution
{
public:
    int calPoints(vector<string>& ops)
    {
        stack<int>stk ;

        for(auto ele : ops)
        {
            if(ele == "C")
                stk.pop() ;
            else if(ele == "D")
                stk.push(2*stk.top()) ;
            else if(ele == "+")
            {
                int record1 = stk.top() ;
                stk.pop() ;
                int record2 = stk.top() ;
                stk.pop() ;
                stk.push(record2) ;
                stk.push(record1) ;
                stk.push(record1 + record2) ;
            }
            else
            {
                int score = stoi(ele) ;
                stk.push(score) ;
            }
        }

        int ans = 0 ;
        while(!stk.empty())
        {
            ans += stk.top() ;
            stk.pop() ;
        }

        return ans ;
    }
};
