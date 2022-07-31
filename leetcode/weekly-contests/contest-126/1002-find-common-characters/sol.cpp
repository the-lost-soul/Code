// Approach 1-->Naive Approach

class Solution 
{
    public:
    vector<string> commonChars(vector<string>& a) 
    {
        unordered_map <char , int> countChar ;
        vector< string > answer ;
        for(auto x : a[0])
        {
            countChar[x] ++ ;
        }
        
        int countOfChar = 0 ;
        
        int minimumCount = 0 ;
        
        for(auto element : countChar)
        {
            minimumCount = element.second ;
            // WOrking Fine
            // cout<<"aquib"<<" ";
            for(auto i = 1 ; i < a.size() ; i++)
            {
                countOfChar = 0 ;
                
                // WOrking Fine
                // cout<<"aquib"<<" ";
                for(auto x : a[i])
                {
                    
                    if(x == element.first)
                    {
                        // WOrking Fine
                        // cout<<"aquib"<<" ";
                        countOfChar ++ ;
                    }
                }
                
                minimumCount = min(minimumCount , countOfChar) ;
            }
            
            if(minimumCount > 0)
            {
                // cout<<"aquib"<<" ";
                char x = element.first ;
                string result(1 , x) ;
                while(minimumCount --)
                {
                    answer.push_back(result) ;
                }
            }
        }
        
        return answer;
        
    }
    
    
};

