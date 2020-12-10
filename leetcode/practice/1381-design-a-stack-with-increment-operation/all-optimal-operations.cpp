class CustomStack 
{
    vector<int>myStack , inc ;
    int maxSize ;
public:
    CustomStack(int maxSize) 
    {
        this->maxSize = maxSize ;
    }
    
    void push(int x) 
    {
        if(myStack.size() >= maxSize)return ;
        myStack.push_back(x) ;
        inc.push_back(0) ;
    }
    
    int pop() 
    {
        int ind = myStack.size() - 1 ;
        if(ind < 0)return -1 ;
        if(ind > 0)inc[ind - 1] += inc[ind] ;
        int top = myStack[ind] + inc[ind];
        inc.pop_back() ;
        myStack.pop_back() ;
        return top ;
    }
    
    void increment(int k, int val) 
    {
        int incrementTill =  min((int)myStack.size() , k) - 1 ;
        if(incrementTill >= 0)inc[incrementTill] += val ;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
