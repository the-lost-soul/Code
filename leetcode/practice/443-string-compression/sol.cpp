class Solution {
public:
    int compress(vector<char>& chars)
    {
        vector<char> ans ;

        for(int i = 0 ; i < chars.size() ;)
        {
            auto ch = chars[i] ;
            int count = 0 ;
            while(i < chars.size() and ch == chars[i])
            {
                i++ ;
                count++ ;
            }

            ans.push_back(ch) ;
            if(count > 1)
            {
                string ct = to_string(count) ;
                for(auto c : ct)
                    ans.push_back((char)c) ;
            }
        }
        chars.resize(ans.size()) ;
        chars = ans ;
        return ans.size() ;
    }
};
