/*we can also use HASHING i.e unordered_map*/
Node *removeDuplicates(Node *root)
{
    //if list contains only one element
    if(root->next==NULL)return root;
    
    //stores count of every node's data
    int count[51]={};
    
    //for traversing the list
    Node *head=root;
    Node *prev=NULL;
    
    /*traverse the list till last node*/
    while(head!=NULL)
    {
        count[head->data]++;
        // when the if statement becomes true
        // i.e we get a duplicate element
        // so delete that
        if(count[head->data]>1)
        {
           prev->next=head->next;
           count[head->data]--;
           free(head);
           head=prev->next;
        }
        else
        {
            prev=head;
            head=head->next;
        }
    }
    
    return root;
}

