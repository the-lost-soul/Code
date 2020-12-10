Approach - 2-- Double traversal of original LL required .
               More readable than approach -1 .


// Should return the head of the copied linked list the 
//output will be 1 if successfully copied
Node * copyList(Node *origHead)
{
    unordered_map<Node * , Node *>hash ;
    
    Node *origCurrent = origHead ;
    Node * cloneCurrent = nullptr ;
    
    // <ake a copy of original list .
    while(origCurrent)
    {
        cloneCurrent =new Node ;
        cloneCurrent->data = origCurrent->data ;
        hash[origCurrent] = cloneCurrent ;
        origCurrent = origCurrent->next ;
    }
    
    // Re-initialise the original list reference again to head .
    origCurrent = origHead ;
    
    // Traverse the original list again to set the next and arbitrary
    // pointer of current node .
    while(origCurrent)
    {
        cloneCurrent = hash[origCurrent] ;
        cloneCurrent->next = hash[origCurrent->next] ;
        cloneCurrent->arb = hash[origCurrent->arb] ;
        origCurrent = origCurrent->next ;
    }
    
    // Return the head of cloned linked list .
    return hash[origHead] ;
}
