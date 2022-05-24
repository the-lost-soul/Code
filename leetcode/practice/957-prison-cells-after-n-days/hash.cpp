class Solution
{
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n)
    {
        vector<vector<int>> hash ;
        vector<int> ans(8 , 0) ;

        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = 1 ; j <= 6 ; j++)
                ans[j] = cells[j - 1] == cells[j + 1] ? 1 : 0 ;

            // Check whether the pattern is repeating or not .
            // Since first and last rows will always be 0 ,
            // so after 2^6 = 64 days pattern will repeat .
            if(hash.size() and hash.front() == ans)
                return hash[(n - i)%hash.size()] ;
            else hash.push_back(ans) ;
            cells = ans ;
        }
        return cells ;
        
    }
};
