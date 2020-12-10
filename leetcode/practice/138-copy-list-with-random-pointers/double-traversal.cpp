class Solution {
public:
    Node* copyRandomList(Node* head) ;
};

Node * Solution :: copyRandomList(Node * origHead)
{
    unordered_map<Node * , Node *>hash ;
    
    Node *origCurrent = origHead ;
    Node * cloneCurrent = nullptr ;
    
    // <ake a copy of original list .
    while(origCurrent)
    {
        cloneCurrent =new Node ;
        cloneCurrent->val = origCurrent->val ;
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
        cloneCurrent->random = hash[origCurrent->random] ;
        origCurrent = origCurrent->next ;
    }
    
    // Return the head of cloned linked list .
    return hash[origHead] ;
    
    }
