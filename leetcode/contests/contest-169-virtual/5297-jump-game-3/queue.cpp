class Solution 
{
    vector<int>dp ;
    public:
        bool canReach(vector<int>& arr, int start) ;
        bool helper(vector<int>& arr , int currInd) ;
};


bool Solution :: canReach(vector<int>& arr , int start)
{
    dp.resize(arr.size() , -1) ;
    queue<int>myQueue ;
    myQueue.push(start) ;
    while(!myQueue.empty())
    {
        int currInd = myQueue.front() ;
        myQueue.pop() ;
        if(currInd >= 0 and currInd < arr.size())
        {
            if(arr[currInd] == 0)return true ;
            if(dp[currInd] == 1)continue ;
            dp[currInd] = 1 ;
            myQueue.push(currInd - arr[currInd]) ;
            myQueue.push(currInd + arr[currInd]) ;
        }
    }
    return false ;
}
