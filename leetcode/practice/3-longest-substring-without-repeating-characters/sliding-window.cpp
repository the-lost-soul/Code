class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char , int> hash ;
        int ans = 0 ;
        int i = 0 , j = 0 ;
        for(j = 0 ; j < s.length() ; j++)
        {
            hash[s[j]]++ ;

            while(hash[s[j]] > 1)
            {
                hash[s[i]] -= 1 ;
                i++ ;
            }
            ans = max(ans , j - i + 1) ;
        }
        return ans == INT_MIN ? 0 : ans ;
    }
};
