class Solution {
public:
    vector<int> sumZero(int n) ;
};

vector<int> Solution :: sumZero(int n)
{
    deque<int>dq ;
    int num = -1 ;
    if(n%2 != 0)
    {
        dq.push_back(0) ;
        n-- ;
    }   
    while(n != 0)
    {
        dq.push_back(abs(num)) ;
        dq.push_front(num) ;
        num-- ;
        n -= 2 ;
    }
    
    vector<int>ans ;
    while(!dq.empty())
    {
        int ele = dq.front() ;
        ans.push_back(ele) ;
        dq.pop_front() ;
    }
    return ans ;
        
}
