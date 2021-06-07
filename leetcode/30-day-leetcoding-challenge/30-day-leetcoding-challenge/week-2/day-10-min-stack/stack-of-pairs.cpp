class MinStack {
public:
    /** initialize your data structure here. */
    stack<int>general ;
    stack<pair<int , int>>minStack ;
    MinStack() 
    {
        
    }
    
    void push(int x) 
    {
        if(minStack.empty())
        {
            minStack.push({x , x}) ;
        }
        else
        {
            int minEle = (minStack.top()).second ;
            minStack.push({x , min(x , minEle)}) ;
        } 
    }
    
    void pop() 
    {
        if(!minStack.empty())
            minStack.pop() ;
    }
    
    int top() 
    {
        return (minStack.top()).first ;
    }
    
    int getMin() 
    {
        return (minStack.top()).second ;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
