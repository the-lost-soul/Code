class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) ;
};

int Solution :: minCostClimbingStairs(vector<int>& cost)
{
    int len = cost.size() ;
    vector<int>answer(len , 0) ;
    for(int i = 0 ; i < len ; i++)
    {
        if(i == 0 or i == 1)answer[i] = cost[i] ;
        else
        {
            answer[i] = cost[i] + min(answer[i - 1] , answer[i - 2]) ;
        }
    }
    return min(answer[len - 1] , answer[len - 2]) ;
}  
