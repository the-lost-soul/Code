class CustomStack 
{
    vector<int>myStack ;
    int maxSize ;
public:
    CustomStack(int maxSize) 
    {
        this->maxSize = maxSize ;
    }
    
    void push(int x) 
    {
        if(myStack.size() < maxSize)myStack.push_back(x) ;
    }
    
    int pop() 
    {
        if(myStack.empty())return -1 ;
        int top = myStack[myStack.size() - 1] ;
        myStack.pop_back() ;
        return top ;
    }
    
    void increment(int k, int val) 
    {
        int incrementTill = myStack.size() > k ? k : myStack.size() ;
        for(int i = 0 ; i < incrementTill ; i++)
        {
            myStack[i] += val ;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
