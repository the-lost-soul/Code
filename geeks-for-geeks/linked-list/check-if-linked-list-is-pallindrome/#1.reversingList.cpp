Node* reverse(Node* head)
{
    Node* prev = NULL ;
    Node* temp ;
    while(head)
    {
        temp = head->next ;
        head->next = prev ;
        prev = head ;
        head = temp ;
    }
    return prev ;
}
/*You are required to complete this method */
bool isPalindrome(Node *head)
{
    if(!head or !head->next)return true ;
    Node* slow = head ;
    Node* fast = head ;
    
    // This keeps track of node prev to slow , and it will
    // help us to get the correct node when length is even .
    Node* prev = NULL ;
    while(fast and fast->next)
    {
        prev = slow ;
        slow = slow->next ;
        fast = fast->next->next ;
    }
    
    Node* temp = NULL ;
    
    // If this condition is true , then this means
    // length of LL is odd .
    if(fast)
    {
        slow->next = reverse(slow->next) ;
        temp = slow->next ;
        while(head != slow)
        {
            if(head->data != temp->data)return false ;
            head = head->next ;
            temp = temp->next ;
        }
    }
    // If we reach here , then LL is of even length .
    else 
    {
        prev->next = reverse(slow) ;
        temp = prev->next ;
        while(head != prev->next)
        {
            if(head->data != temp->data)return false ;
            head = head->next ;
            temp = temp->next ;
        }
    }
    
    return true ;
}
