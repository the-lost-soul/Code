Node *compute(Node *head)
{
    // your code goes here
    Node *current=head;
    Node *temp=head;

    //if only one node is present
    if(current->next==NULL)return head;
    
    //if more than 2 nodes are present
    //then recursively call the function
    //for next node i.e current->next
    if(current->next->next!=NULL)
    {
        head->next=compute(current->next);
    }
  
    if(current->data<current->next->data)
    {
        temp=current->next;
        free(current);
        head=temp;
    }
    return head;
    
    
}

