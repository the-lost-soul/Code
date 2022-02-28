class Solution {
public:
    int minOperations(vector<string>& logs) ;
};

int Solution :: minOperations(vector<string>& logs)
{
    int min_steps = 0 ;
    for(auto operations : logs)
    {
        if(operations[0] == '.' and operations[1] == '/')continue ;
        if(operations[0] == '.' and operations[1] == '.')
            min_steps  = min_steps > 0 ? min_steps - 1 : 0  ;
        else min_steps++ ;
    }
    return min_steps > 0 ? min_steps : 0 ;
}
