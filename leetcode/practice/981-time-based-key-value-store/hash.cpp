class TimeMap
{
    unordered_map<string , vector<pair<int , string>>> hash ;
public:
    TimeMap()
    {
        
    }
    
    void set(string key, string value, int timestamp)
    {
        hash[key].push_back({timestamp , value}) ;
    }
    
    string get(string key, int timestamp)
    {
        if(hash.find(key) == hash.end())
            return "" ;

        int left = 0 , right = hash[key].size() - 1 ;
        while(left <= right)
        {
            int mid = left + (right - left)/2 ;
            if(hash[key][mid].first > timestamp)
                right = mid - 1 ;
            else
                left = mid + 1 ;
        }

        return left > 0 and left <= hash[key].size() ? hash[key][left - 1].second : "" ;
        
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
