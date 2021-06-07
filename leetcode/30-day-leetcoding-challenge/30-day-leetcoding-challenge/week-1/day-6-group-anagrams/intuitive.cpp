class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) ;
} ;

vector<vector<string>> Solution :: groupAnagrams(vector<string>& strs)
{
    if(size(strs) == 0)return {} ;
    vector<vector<string>>res ;
    vector<string>group ;
    vector<int>hash(26 , 0) , temp(26 , 0) ;
    queue<int>myQueue ;
    for(auto ch : strs[0])
        hash[ch - 'a']++ ;
    group.push_back(strs[0]) ;
    for(int i = 1 ; i < size(strs) ; i++)
    {
        fill(begin(temp) , end(temp) , 0) ;
        for(auto ch : strs[i])
            temp[ch - 'a']++ ;
        if(hash == temp)
            group.push_back(strs[i]) ;
        else 
            myQueue.push(i) ;
    }
    res.push_back(group) ;
    
    while(!myQueue.empty())
    {
        int ind = myQueue.front() ;
        myQueue.pop() ;
        fill(begin(hash) , end(hash) , 0) ;
        for(auto ch : strs[ind])
            hash[ch - 'a']++ ;
        group.clear() ;
        group.push_back(strs[ind]) ;
        queue<int>tempQueue ;
        while(!myQueue.empty())
        {
            fill(begin(temp) , end(temp) , 0) ;
            ind = myQueue.front() ;
            myQueue.pop() ;
            for(auto ch : strs[ind])
                temp[ch - 'a']++ ;
            if(temp == hash)
                group.push_back(strs[ind]) ;
            else
                tempQueue.push(ind) ;
        }
        myQueue = tempQueue ;
        res.push_back(group) ;
    }
    return res ;
}
