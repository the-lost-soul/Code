struct node* pairWiseSwapUtil(struct node* head)
{
    if(!head)return head ;
    if(!head->next)return head ;
    
    // Swap the first two nodes 
    struct node* temp = head->next->next ;
    struct node* newHead = head->next ;
    newHead->next = head ;
    // Go ahead with other nodes 
    newHead->next->next = pairWiseSwapUtil(temp) ;
    return newHead ;
    
}
void pairWiseSwap(struct node *head)
{

    // Head is modified here but not in the "main()" function .
    head = pairWiseSwapUtil(head) ;
    
    /* We are doing this because after changing links all the
     * other nodes will be at their correct position and will be
     * printed correctly except first two nodes because head will
     * not be modified in the "main()" function as it is not passed 
     * by reference so , to get the correct result we have to print
     * the first node of the resultant swapped LL
     */
    if(head->next)printf("%d " , head->data) ;
}
