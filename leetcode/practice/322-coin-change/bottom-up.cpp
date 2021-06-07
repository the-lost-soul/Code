class Solution {
public:
    int coinChange(vector<int>& coins, int amount) ;
};

int Solution :: coinChange(vector<int>& coins , int amount)
{
    vector<int>denominations(amount + 1 , amount + 1) ;
    denominations[0] = 0 ;
    for(int i = 1 ; i <= amount ; i++)
    {
        for(int j = 0 ; j < coins.size() ; j++)
        {
            if(i >= coins[j])
                denominations[i] = min(denominations[i] , denominations[i - coins[j]] + 1) ;
        }
    }
    return denominations[amount] > amount ? - 1 : denominations[amount] ;
}
