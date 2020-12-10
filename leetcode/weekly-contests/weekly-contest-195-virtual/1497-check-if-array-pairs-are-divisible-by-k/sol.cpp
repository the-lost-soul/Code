class Solution {
public:
    bool canArrange(vector<int>& arr, int k) ;
};

bool Solution :: canArrange(vector<int>& arr, int k)
{
    unordered_map<int , int>hash ;
    for(auto num : arr)
    {
        int rem = num%k ;
        if(rem < 0)rem += k ;
        hash[rem%k]++ ;
    }
    for(auto num : arr)
    {
        int r1 = num%k ;
        if(r1 < 0)r1 += k ;
        r1 %= k ;
        if(r1 == 0)
        {
            if(hash[r1]%2 != 0)return false ;
        }
        else if(hash[k - r1] != hash[r1])return false ; 
        
    }
    return true ;
}
