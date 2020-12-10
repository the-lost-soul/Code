class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) ;
};

string Solution :: stringShift(string s , vector<vector<int>>& shift)
{
    deque<char>string ;
    for(auto ch : s)
        string.push_back(ch) ;
    for(auto details : shift)
    {
        int direction = details[0] ;
        int amount = details[1] ;
        if(direction == 0)
        {
            while(amount-- > 0)
            {
                char ch = string.front() ;
                string.pop_front() ;
                string.push_back(ch) ;
            }
        }
        else
        {
            while(amount-- > 0)
            {
                char ch = string.back() ;
                string.pop_back() ;
                string.push_front(ch) ;
            }
        }
    }
    
    s = "" ;
    while(!string.empty())
    {
        s += string.front() ;
        string.pop_front() ;
    }
    return s ;
}
