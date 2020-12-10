void linkdelete(struct node  *head, int M, int N)
{
    //Add code here 
    // If no node is present
    if(head==NULL)return ;
    // If only one node is presenr
    if(head->next==NULL) return ;
    // Variable to skip M nodes
    int count=0;
    
    struct node *current=head;
    struct node *next=head;
    struct node *prev=NULL;
    /* Traverse M nodes */
    while(current!=NULL && count<M)
    {
        prev=current;
        current=current->next;
        count++;
    }
    // set count to 0,and delete N nodes 
    //after M nodes
    count=0;
    /* Delete N nodes */
    while(current!=NULL && count<N)
    {
        prev->next=current->next;
        free(current);
        current=prev->next;
        count++;
    }
    //if more nodes are present ahead of 
    //the node pointed by prev
    if(prev->next!=NULL)
    {
        linkdelete(prev->next,M,N);
    }
    
}


