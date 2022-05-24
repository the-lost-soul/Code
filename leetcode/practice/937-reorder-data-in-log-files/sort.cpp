class Solution
{

    vector<pair<string , string>>letterLog ;
    vector<string>digitLog ;
public:
    static bool comp(pair<string , string> a , pair<string , string> b)
    {
        if(a.first == b.first)
            return a.second < b.second ;
        return a.first < b.first ;
    }

    void insertLog(string log)
    {
        int ind = log.find(' ') ;
        if(islower(log[ind + 1]))
            letterLog.push_back({log.substr(ind + 1) , log.substr(0 , ind)}) ;
        else digitLog.push_back(log) ;
    }

    vector<string> reorderLogFiles(vector<string>& logs)
    {
        for(auto log : logs)
            insertLog(log) ;

        sort(letterLog.begin() , letterLog.end() , comp) ;
        vector<string>ans ;
        for(auto log : letterLog)
            ans.push_back(log.second + " " + log.first) ;
        for(auto log : digitLog)
            ans.push_back(log) ;
        return ans ;
    }
};
