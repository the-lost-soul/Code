class Solution
{
public:
    int numUniqueEmails(vector<string>& emails)
    {
        unordered_set<string>hash ;
        for(auto str : emails)
        {
            int len = str.size() , i = 0 ;
            string local = "" , domain = "" ;
            while(str[i] != '@' and i < len)
            {
                local += str[i] ;
                i++ ;
            }
            i++ ;
            while(i < len)
            {
                domain += str[i] ;
                i++ ;
            }
            // Now remove the additional chars from local name .
            i = 0 , len = local.size() ;
            string temp = local ;
            local = "" ;
            while(temp[i] != '+' and i < len)
            {
                if(temp[i] != '.')
                    local += temp[i] ;
                i++ ;
            }
            hash.insert(local + "@" +  domain) ;
        }
        return hash.size() ;
    }
};
