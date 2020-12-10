class Solution 
{
public:
    int countTriplets(vector<int>& arr) ;
};

int Solution :: countTriplets(vector<int>& arr)
{
    vector<int>clone = arr ;
    clone.insert(clone.begin() , 0) ;
    for(int i = 1 ; i < clone.size() ; i++)
    {
        clone[i] ^= clone[i - 1] ;
    }
    int ans = 0 ;
    unordered_map<int , int>count , total ;
    for(int i = 0 ; i < clone.size() ; ++i)
    {
        ans += (count[clone[i]]++)*(i - 1) - total[clone[i]] ;
        total[clone[i]] += i ;
    }
    return ans ;
}
