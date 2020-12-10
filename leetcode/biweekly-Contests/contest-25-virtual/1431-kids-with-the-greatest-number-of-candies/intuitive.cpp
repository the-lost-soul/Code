class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) ;
};

vector<bool> Solution ::  kidsWithCandies(vector<int>& candies, int extraCandies)
{
    int maxCandies = *max_element(begin(candies) , end(candies)) ;
    
    vector<bool>ans ;
    for(auto ele : candies)
    {
        bool possible = ele + extraCandies >= maxCandies ;
        ans.push_back(possible) ;       
    }
    return ans ;
}
