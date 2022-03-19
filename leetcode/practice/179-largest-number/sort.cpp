class Solution {
public:
    static bool comp(const string& s1 , const string& s2)
    {
        string a = s1 + s2 ;
        string b = s2 + s1 ;
        return a > b ;
    }
    string largestNumber(vector<int>& nums)
    {
        
        vector<string> temp ;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            temp.push_back(to_string(nums[i])) ;
        }
        
        sort(temp.begin() , temp.end() , comp) ;
        
        string ans = "" ;
        for(auto ele : temp)
            ans += ele ;
        return ans[0] == '0' ? "0" : ans ;
        
    }
};
