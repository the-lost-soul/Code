int getMiddle(Node *head)
{
    Node* mid = head ;
    int countOfNode = 0 ;
    while(head)
    {
        // update mid when count is odd number .
        if(countOfNode & 1)mid = mid->next ;
        
        countOfNode++ ;
        head = head->next ;
    }
    
    if(mid)
    return mid->data ;
    else return -1 ;
}
