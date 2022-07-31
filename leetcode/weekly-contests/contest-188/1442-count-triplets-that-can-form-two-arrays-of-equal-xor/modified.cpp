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
    for(int i = 0 ; i < clone.size() ; ++i)
    {
        int a = clone[i] ;
        for(int j = i + 1 ; j < clone.size() ; ++j)
        {
            int b = clone[j] ;
            if(clone[i] == clone[j])
                ans += (j - i - 1) ;
        }
    }
    return ans ;
}
