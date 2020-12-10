class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) ;
 
};

bool comp(vector<int> a , vector<int> b)
{
    return a[1] - a[0] < b[1] - b[0] ;
}
int Solution :: twoCitySchedCost(vector<vector<int>>& costs)
{
    int minCost = 0 ;
    for(auto cost : costs)
        minCost += cost[0] ;
    
    sort(begin(costs) , end(costs) , comp) ;
    for(int i = 0 ; i < costs.size()/2 ; i++)
    {
        minCost -= costs[i][0] ;
        minCost += costs[i][1] ;
    }

    return minCost ;
}
