class Solution {
public:
    int max_req ;
    int maximumRequests(int n, vector<vector<int>>& requests) ;
    void helper(vector<vector<int>>& requests , vector<int>& count , int index , int curr_req) ;
};

// Remember to pass the 2-D vector "requests" and vector "count" as reference .
void Solution :: helper(vector<vector<int>>& requests , vector<int>& count , int index , int curr_req)
{
    if(index == requests.size())
    {
        for(auto ele : count)if(ele != 0)return ;
        max_req = max(max_req , curr_req) ;
        return ;
    }
    
    // Don't process the current request .
    helper(requests , count , index + 1 , curr_req) ;
    
    // Process the current request .
    count[requests[index][0]]-- ;
    count[requests[index][1]]++ ;
    helper(requests , count , index + 1 , curr_req + 1) ;
    
    // Come back to the same state .
    count[requests[index][0]]++ ;
    count[requests[index][1]]-- ;
    
}

int Solution :: maximumRequests(int n , vector<vector<int>> & requests)
{
    max_req = 0 ;
    vector<int>count(n , 0) ;
    helper(requests , count , 0 , 0) ;
    return max_req ;
    
}
