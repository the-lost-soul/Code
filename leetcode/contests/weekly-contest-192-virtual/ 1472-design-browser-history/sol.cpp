class BrowserHistory 
{
    vector<string>history ;
    int currPage = 0 ;
public:
    BrowserHistory(string homepage) 
    {
        history.push_back(homepage) ;
        currPage = 0 ;
    }
    
    void visit(string url) 
    {
        history.resize(currPage + 1) ;
        history.push_back(url) ;
        currPage++ ;  
    }
    
    string back(int steps) 
    {
        if(currPage > steps)currPage -= steps ;
        else currPage = 0 ;
        return history[currPage] ;
    }
    
    string forward(int steps) 
    {
        if(history.size() - currPage > steps)currPage += steps ;
        else currPage = history.size() - 1 ;
        return history[currPage] ;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
