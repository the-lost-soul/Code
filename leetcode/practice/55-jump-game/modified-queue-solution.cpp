class Solution {
public:
    bool canJump(vector<int>& nums) ;
};

bool Solution :: canJump(vector<int>& nums)
{
    unordered_set<int>hash ;
    queue<int>myQueue ;
    myQueue.push(0) ;
    while(!myQueue.empty())
    {
        int currInd = myQueue.front() ;
        myQueue.pop() ;
        if(currInd == nums.size() - 1)return true ;
        int jumpVal = nums[currInd] ;
        while(jumpVal > 0)
        {
            int jumpedInd = currInd + jumpVal ;
            if(jumpedInd < nums.size())
            {
                // Putting this if statement here eliminates TLE .
                // This gives TLE -- if(jumpedInd < nums.size() and 
                //                     hash.find(jumpedInd) == hash.end())
                if(hash.find(jumpedInd) == hash.end())
                {
                    hash.insert(jumpedInd) ;
                    myQueue.push(jumpedInd) ;
                }
                else break ;
            }
            jumpVal-- ;
        }
        
    }
    return false ;
}
