class MinStack {
public:
    /** initialize your data structure here. */
    stack<int>general ;
    stack<int>minStack ;
    MinStack() 
    {
        
    }
    
    void push(int x) 
    {
        general.push(x) ;
        stack<int>myStack ;
        while(!minStack.empty() and x > minStack.top())
        {
            myStack.push(minStack.top()) ;
            minStack.pop() ;
        }
        minStack.push(x) ;
        while(!myStack.empty())
        {
            minStack.push(myStack.top()) ;
            myStack.pop() ;
        }
        
        
    }
    
    void pop() 
    {
        int ele = general.top() ;
        general.pop() ;
        stack<int>myStack ;
        while(!minStack.empty() and ele != minStack.top()) 
        {
            myStack.push(minStack.top()) ;
            minStack.pop() ;
        }
        minStack.pop() ;
        while(!myStack.empty())
        {
            minStack.push(myStack.top()) ;
            myStack.pop() ;
        }
    }
    
    int top() 
    {
        return general.top() ;
    }
    
    int getMin() 
    {
        return minStack.top() ;
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
