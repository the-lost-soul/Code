class CombinationIterator 
{
    string temp = "" ;
    int len , curr ;
    vector<string>ans ;
    void dfs(string s , int len)
    {
        if(s.length() == this->len)
        {
            ans.push_back(s) ;
            return ;
        }
        if(len == temp.length())return ;
        dfs(s , len + 1) ;
        s += temp[len] ;
        dfs(s , len + 1) ;
    }
    public:
        CombinationIterator(string s, int combinationLength) 
        {
            temp = s ;
            len = combinationLength ;
            dfs("" , 0) ;
            sort(ans.begin() , ans.end()) ;
            curr = 0 ;
        }

        string next() 
        {
            return ans[curr++] ;

        }

        bool hasNext() 
        {
            return curr < ans.size() ;

        }
} ;

/*
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
