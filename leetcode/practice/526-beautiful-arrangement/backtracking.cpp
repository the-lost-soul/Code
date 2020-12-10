class Solution {
public:
    int count ;
    int countArrangement(int N) ;
    void helper(int N , int index , vector<bool>& visited) ;
};

void Solution :: helper(int N , int index , vector<bool>& visited)
{
    if(index > N)
    {
        count++ ;
        return ;
    }
    
    for(int i = 1 ; i <= N ; i++)
    {
        if(!visited[i] and (i%index == 0 or index%i == 0))
        {
            visited[i] = true ;
            helper(N , index + 1 , visited) ;
            visited[i] = false ;
        }
    }
}

int Solution :: countArrangement(int N)
{
    count = 0 ;
    vector<bool>visited(N + 1 , false) ;
    visited[0] = true ;
    int index = 1 ;
    helper(N , index , visited) ;
    return count ;
    
}
