Node* deleteMid(Node *head)
{
    // Your Code Here
    //if list is EMPTY
    if(head==NULL) return NULL;
    //if list contains 1 node only
    else if(head->next==NULL)
    
        free(head);
        return NULL;
    
    //if list contains more than one node
    else
    
        Node *slow=head;
        Node *fast=head->next;
        Node *prev=head;
        Node *temp;
        // cout<<slow->data;
        
        //traverse the list and on termination of the loop
        //we will get the slow node that will point to
        //middle element
        while(fast!=NULL && fast->next!=NULL)
        
            // cout<<slow->data<<" ";
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        
        //if fast!=NULL then linked list contains even 
        //number of nodes,SO we FREE the node i.e
        //next of slow
        if(fast!=NULL)
        
            prev=slow->next;
            slow->next=slow->next->next;
            free(prev);
        
        //fast is NULL so linked list contains
        //odd numbered nodes,SO we FREE the node
        //pointed by slow
        else
        
            prev->next=slow->next;
            free(slow);
        
        return head;
    
}

