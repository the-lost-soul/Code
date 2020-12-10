class Solution {
public:
    int findSpecialInteger(vector<int>& arr) ;
};

int Solution :: findSpecialInteger(vector<int>& arr)
{
    int freq = arr.size()/4 ;
    unordered_map<int , int>hash ;
    int ans = 0 ;
    for(int i = 0 ; i < arr.size() ; i++)
    {
        hash[arr[i]]++ ;
        if(hash[arr[i]] > freq)ans = arr[i] ;
    }
    return ans ;
}
