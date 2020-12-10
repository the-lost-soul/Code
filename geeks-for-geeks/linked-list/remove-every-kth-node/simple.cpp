Node * deleteK(Node *root,int K)
{
 
    //if no node is to be deleted
    if(K==0)return root;
    
    //for traversing the list
    Node *head=root;
    
    //used during deletion i.e. when we 
    //delete a node than we have to link
    //list with help of prev
    Node *prev=root;
    
    //for counting the nodes
    int count=0;
    
    //traverse till last node
    while(head!=NULL)
    {
        count++;
        
        //if the node to be deleted is 
        //always the first node i.e k=1
        if(K==1&&count==K)
        {
            root=root->next;
            free(prev);
            prev=root;
            head=root;
            //again initialise count of nodes to zero
            count=0;
        }
        
        //if k is greater than 1 and count
        //becomes equal to k
        else if(count==K)
        {
            prev->next=head->next;
            free(head);
            head=prev->next;
            
            //again initialise count of nodes to zero
            count=0;
           
            
        }
        
        //if count is less than k
        else
        {
            prev=head;
            head=head->next;
        }
    }
    return root;
}


