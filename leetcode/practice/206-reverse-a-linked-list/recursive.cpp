class Solution 
{
    private:
    ListNode * next = NULL ;
    ListNode * lastNode = NULL ;
    
    public:
    ListNode* reverseList(ListNode* head) ;
};


ListNode * Solution :: reverseList(ListNode * head )
{
    // If list is empty or has one element , then no need to reverse .
    if(!head || !head->next)
    {
        // For a list with one element the last Node will be the head itself .
        lastNode = head ;
        return head ;
    }
    
    // Store the head of reversed list which lies ahead of current node .
    head->next = reverseList(head->next) ;
    
    // Store the first node of current sub-list i.e the reversed list .
    next = head->next ;
    
    // Assign "NULL" to current node's next , as it will be the 
    // last node of the new reversed list . 
    head->next = nullptr ;
    
    // Connect the current node to end of reverse list .
    lastNode->next = head ;
    
    // Update the last node as the current element will become
    // the last node after above process .
    lastNode = head ;
    
    // Return the head of the reversed list.
    return next ;
   
   }
