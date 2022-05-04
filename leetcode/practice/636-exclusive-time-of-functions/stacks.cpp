class Solution
{
    struct Log
    {
        int id ;
        int timestamp ;
        bool indicator ;
    };

    Log parseLog(string str)
    {
        stringstream s(str) ;
        string id , timestamp , indicator ;
        getline(s , id , ':') ;
        getline(s , indicator , ':') ;
        getline(s , timestamp , ':') ;
        return {stoi(id) , stoi(timestamp) , indicator == "start" } ;
    }
        
public:
    vector<int> exclusiveTime(int n, vector<string>& logs)
    {
        vector<int>result(n , 0) ;
        stack<Log>stk ;
        for(auto ele : logs)
        {
            Log currLog = parseLog(ele) ;
            if(currLog.indicator)
                stk.push(currLog) ;
            else
            {
                int time = currLog.timestamp - stk.top().timestamp + 1 ;
                result[currLog.id] += time ;
                stk.pop() ;
                if(stk.empty() == false)
                    result[stk.top().id] -= time ;
            }
        }
        return result ;
    }
};
