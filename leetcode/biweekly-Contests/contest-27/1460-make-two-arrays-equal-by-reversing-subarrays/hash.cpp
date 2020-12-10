class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) ;
};
bool Solution :: canBeEqual(vector<int>& target , vector<int>& arr)
{
    unordered_map<int , int> hash ;
    for(int i = 0 ; i < target.size() ; i++)
    {
        hash[target[i]]++ ;
    }
    int count = 0 ;
    for(int i = 0 ; i < arr.size() ; i++)
    {
        if(hash[arr[i]] > 0)
        {
            hash[arr[i]]-- ;
            count++ ;
        }
    }
    return count == arr.size() ;
}
