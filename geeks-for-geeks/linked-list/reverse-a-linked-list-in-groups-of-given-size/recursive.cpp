struct node *reverse (struct node *head, int K)
{ 
    // Complete this method
    /*geeks for geeks solution*/
/*another way to solve this is by using stack*/

    struct node *current=head;
    struct node *next=head;
    struct node *prev=NULL;
    int count=0;

    /*reverse first K nodes of list*/
    while(count<K&&current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
        count++;
    }
    
    //now next points to (K+1)th node
    //so recursively call for kth node
    if(next!=NULL)
    {
        head->next=reverse(current,K);
    }
    //new head of input list
    return prev;
}


