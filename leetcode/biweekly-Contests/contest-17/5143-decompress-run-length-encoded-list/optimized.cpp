class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) ;
};

vector<int> Solution :: decompressRLElist(vector<int>& nums)
{
    vector<int>decompress ;
    for(int i = 0 ; i < nums.size() ; i += 2)
    {
        for(int j = 0 ; j < nums[i] ; j++)
        {
            decompress.push_back(nums[i + 1]) ;
        }
    }
    return decompress ;
}
