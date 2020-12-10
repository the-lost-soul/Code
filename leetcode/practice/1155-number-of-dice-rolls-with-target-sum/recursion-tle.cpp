class Solution {
    const int mod = 1e9 + 7 ;
public:
    int numRollsToTarget(int d, int f, int target) ;
};

int Solution :: numRollsToTarget(int d , int f , int target)
{
    if(target == 0 and d == 0)
        return 1 ;
    if(target <= 0 or d == 0)
        return 0 ;
    int count = 0 ;
    for(int val = 1 ; val <= f ; val++)
    {
        count = (count + numRollsToTarget(d - 1 , f , target - val))%mod ;
    }
    return count%mod ;
}
