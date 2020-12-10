class Solution {
public:
    int numSquares(int n) ;
};
int Solution :: numSquares(int n)
{
    vector<int>perfectSquares , count(n + 1 , 0) ;
    for(int i = 1 ; i*i <= n ; i++)
    {
        perfectSquares.push_back(i*i) ;
        count[i] = 1 ;
    }
    if(perfectSquares.back() == n)
        return 1 ;
    queue<int>myQueue ;
    for(auto ele : perfectSquares)
    {
        myQueue.push(ele) ;
    }
    
    int ans = 0 ;
    int squareCount = 1 ;
    while(!myQueue.empty())
    {
        squareCount++ ;
        int qSize = myQueue.size() ;
        for(int i = 0 ; i < qSize ; i++)
        {
            int node = myQueue.front() ;
            myQueue.pop() ;
            for(auto ele : perfectSquares)
            {
                if(node + ele == n)
                    return squareCount ;
                else if(node + ele < n)
                {
                    if(count[node + ele] == 0)
                    {
                        count[node + ele] = squareCount ;
                        myQueue.push(node + ele) ;
                    }
                }
                else
                {
                    break ;
                }
            }
        }
    }
    return 0 ;
    
}
