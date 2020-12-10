class Solution 
{
    private:
    ListNode * next = NULL ;
    
    public:
    ListNode* reverseList(ListNode* head) ;
    ListNode* helper(ListNode *head , ListNode *prev = nullptr) ;
};

ListNode * Solution :: reverseList(ListNode *head)
{
    return helper(head , nullptr) ;
    
}

ListNode * Solution :: helper(ListNode * head , ListNode *prev)
{
    // Empty List .
    if(!head) return nullptr ;
    
    // Traverse till end .
    while(head)
    {
        
        next = head->next ;
        
        // Add the current node to the front of reversed list .
        head->next = prev ;
        
        // This keeps track of the front of reversed list .
        prev = head ;
        
        // Update the unreversed list's head to original elements next .
        head = next ;
    }
    
    // Remember to return previous element as current will be "NULL"
    return prev ;
    
    
    
}
