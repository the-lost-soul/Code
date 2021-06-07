class Solution {
public:
    int countElements(vector<int>& arr) ;
};

int Solution :: countElements(vector<int>& arr)
{
    unordered_map<int , int>hash ;
    for(auto ele : arr)
        hash[ele]++ ;
    int ans = 0 ;
    for(auto itr : hash)
    {
        int next = itr.first + 1 ;
        if(hash.find(next) != hash.end())
        {
            ans += itr.second ;
        }
    }
    return ans ;
}
