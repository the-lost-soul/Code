class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) ;
};

vector<int> Solution :: findDiagonalOrder(vector<vector<int>>& nums)
{
    map<int , vector<int>>hash ;
    for(int i = 0 ; i < nums.size() ; i++)
    {
        for(int j = 0 ; j < nums[i].size() ; j++)
        {
            if(hash.find(i + j) == hash.end())
            {
                hash[i + j] = vector<int>() ;
            }
            hash[i + j].push_back(nums[i][j]) ;
        }
    }
    vector<int>ans ;
    for(auto details : hash)
    {
        vector<int>myVector = details.second ;
        reverse(begin(myVector) , end(myVector)) ;
        int j = 0 ;
        while(j < myVector.size())
        {
            ans.push_back(myVector[j++]) ;
        }
    }
    return ans ;
}
