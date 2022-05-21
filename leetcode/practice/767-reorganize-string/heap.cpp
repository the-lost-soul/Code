class Solution
{
public:
    string reorganizeString(string s)
    {
        map<char , int>charCount ;
        for(auto ch : s)
            charCount[ch]++ ;

        priority_queue<pair<int , char>>maxHeap ;
        for(auto ele : charCount)
        {
            maxHeap.push({ele.second , ele.first}) ;
        }

        string ans = "" ;
        while(!maxHeap.empty())
        {
            pair<int , char> top = maxHeap.top() ;
            maxHeap.pop() ;
            ans += top.second ;

            if(!maxHeap.empty())
            {
                pair<int , char> newTop = maxHeap.top() ;
                maxHeap.pop() ;
                ans += newTop.second ;
                if(newTop.first > 1)
                    maxHeap.push({newTop.first - 1 , newTop.second}) ;
            }

            if(top.first > 1)
                maxHeap.push({top.first - 1 , top.second}) ;
        }
        for(int i = 1 ; i < ans.size() ; i++)
        {
            if(ans[i] == ans[i - 1])
                return "" ;
        }
        return ans ;
    }
};
