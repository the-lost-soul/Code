class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) ;
};

vector<int> Solution :: decompressRLElist(vector<int>& nums)
{
    vector<int>decompress ;
    for(int i = 0 ; i < nums.size() ; i++)
    {
        if(2*i < nums.size() and 2*i + 1 < nums.size())
        {
            int a = nums[2*i] ;
            int b = nums[2*i + 1] ;
            for(int j = 1 ; j <= a ; j++)
                decompress.push_back(b) ;
        }
    }
    return decompress ;
}
