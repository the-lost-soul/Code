int getMiddle(Node *head)
{
    if(!head)return -1 ;
    Node* slow = head ;
    Node* fast = head ;
    
    /* Here when fast will be reach end , then
     * slow will be at middle
     */
    while(fast and fast->next)
    {
        slow = slow->next ;
        fast = fast->next->next ;
    }
    return slow->data ;
}
