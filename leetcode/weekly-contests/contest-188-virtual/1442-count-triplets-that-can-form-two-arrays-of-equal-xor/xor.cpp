class Solution 
{
public:
    int countTriplets(vector<int>& arr) ;
};

int Solution :: countTriplets(vector<int>& arr)
{
    vector<int>clone = arr ;
    for(int i = 1 ; i < clone.size() ; i++)
    {
        clone[i] = clone[i]^clone[i - 1] ;
    }
    int ans = 0 ;
    for(int i = 0 ; i < clone.size() ; i++)
    {
        int a = clone[i] ;
        for(int j = i + 1 ; j < clone.size() ; j++)
        {
            int b = clone[j] ;
            if(a == b)
                ans += (j - i - 1) ;
        }
    }
    // Count all the sub-arrays from 0 till index i whose xor is "0" .
    for(int i = 0 ; i < clone.size() ; i++)
    {
        if(clone[i] == 0)
        {
            ans += i ;
        }
    }
    return ans ;
}
