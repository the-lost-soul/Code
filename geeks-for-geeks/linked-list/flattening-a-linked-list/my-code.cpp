/* MY SOLUTION AFTER SEEING BHAIYYA’S CODE */

/*  Function which returns the  root of 
    the flattened linked list. */
Node *merge(Node *a , Node *b)
{
    // If first linked list is empty then return b
    if(a == NULL)return b ;
    // if second linked llist is empty then return a;
    if(b == NULL)return a ;
    
    // This stores the new sorted list
    Node *result = NULL ;
    // if data of first list is greater
    // then second list goes first
    if(a->data > b->data)
    {
        result = b ; 
        b->bottom = merge(a , b->bottom) ;
    }
    // If data of second list is greater then
    // first list goes first
    else
    {
        result = a ;
        a->bottom = merge(a->bottom , b) ;
    }
    return result ;
}
/* Block all the next pointer of vertical list */
void block(Node *result)
{
    // Traverse the vertical list downward
    while(result->bottom != NULL)
    {
        // if at any point we get a node whose
        // next pointer is not NULL then make that NULL
        if(result->next != NULL)result->next = NULL ;
        result = result->bottom ;
    }
}
Node *flatten(Node *root)
{
    // if list is empty then return;
    if(root == NULL)return NULL ;
    // If right Linked List is not present
    // then answer is bottom linked list
    if(root->next == NULL)return root ;
    // Traverse the list horizontally till end
    // to get the sublist
    Node *subresult = flatten(root->next) ;
    // merge the sublist with its prev list
    Node *result = merge(root , subresult) ;
    // It helps in making the next pointer of
    // the newly created vertical list NULL
    block(result) ;
    return result ;
    
}
