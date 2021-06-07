class Solution {
public:
    vector<int> partitionLabels(string S) ;
};

vector<int> Solution :: partitionLabels(string s)
{
    vector<int>count(26 , 0) ;
    for(auto ch : s)
        count[ch - 'a']++ ;
    vector<int>ans ;
    queue<char>myQueue ;
    vector<bool>visited(26 , false) ;
    int start = 0 ;
    for(int i = 0 ; i < s.size() ; i++)
    {
        int num = s[i] - 'a' ;
        count[num]-- ;
        if(count[num] > 0 and visited[num] == false)
        {
            myQueue.push(s[i]) ;
            visited[num] = true ;
        }
        
        if(count[num] == 0)
        {
            queue<char>temp ;
            while(!myQueue.empty())
            {
                auto ch = myQueue.front() ;
                myQueue.pop() ;
                if(count[ch - 'a'] == 0 || s[i] == ch)continue ;
                temp.push(ch) ;
            }
            while(!temp.empty())
            {
                auto ch = temp.front() ;
                temp.pop() ;
                myQueue.push(ch) ;
            }
            if(myQueue.empty())
            {
                ans.push_back(i - start + 1) ;
                start = i + 1 ;
            }
        }
    }
    return ans ;
}
