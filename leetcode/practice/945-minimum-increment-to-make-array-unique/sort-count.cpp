class Solution {
public:
    int minIncrementForUnique(vector<int>& A) ;
};

int Solution :: minIncrementForUnique(vector<int>& arr)
{
    unordered_map<int , int>hash ;
    vector<int>used ;
    sort(begin(arr) , end(arr)) ;
    int ans = 0 ;
    for(auto ele : arr)
        hash[ele]++ ;
    for(int i = 0 ; i <= 100000 ; i++)
    {
        if(hash.find(i) != hash.end())
        {
            if(hash[i] >= 2)
            {
                int count = hash[i] - 1 ;
                for(int j = 0 ; j < count ; j++)
                {
                    used.push_back(i) ;
                }
            }
        }
        else if(size(used) != 0 and hash.find(i) == hash.end())
        {
            cout << ans ;
            ans += i - used[used.size() - 1] ;
            used.pop_back() ;
        }
    }
    return ans ;
}
