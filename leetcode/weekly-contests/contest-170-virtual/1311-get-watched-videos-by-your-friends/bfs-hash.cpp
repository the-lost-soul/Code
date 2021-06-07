class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watched , vector<vector<int>>& friends, int id, int level) ;
};

vector<string> Solution :: watchedVideosByFriends(vector<vector<string>>& watched , vector<vector<int>>& friends, int id, int level) 
{
    queue<int>myQueue ;
    myQueue.push(id) ;
    myQueue.push(-1) ;
    vector<bool>visited(friends.size()) ;
    visited[id] = true ;
    while(!myQueue.empty() and level > 0)
    {
        int person = myQueue.front() ;
        myQueue.pop() ;
        if(person == -1)
        {
            level-- ;
            myQueue.push(-1) ;
            continue ;
        }
        for(auto f : friends[person])
        {
            if(!visited[f])
            {
                visited[f] = true ;
                myQueue.push(f) ;
            }
        }   
    }
    unordered_map<string , int>hash ;
    while(!myQueue.empty())
    {
        int person = myQueue.front() ;
        myQueue.pop() ;
        if(person == -1)continue ;
        for(auto vid : watched[person])
            hash[vid]++ ;
    }
    set<pair<int , string>>mySet ;
    for(auto details : hash)
    {
        mySet.insert({details.second , details.first}) ;
    }
    vector<string>ans ;
    for(auto details : mySet)
    {
        ans.push_back(details.second) ;
    }
    return ans ;
}
