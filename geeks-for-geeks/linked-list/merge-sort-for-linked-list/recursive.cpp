/* split the nodes of the given list into front and back halves,
 *  and return the two lists using the reference parameters.
 */
void splitList(struct node* source , struct node** frontRef , struct node** backRef)
{
    
    struct node *slow = source ;
    /* I started from source->next because
     * for n==2 or any even number of nodes
     * the program will give segmentation fault
     * because when n==2 then for infinite time 
     * my splitList function will be splitted i.e
     * (*bckRef)'ll become NULL and (*frontRef)
     * will be of length 2 each time we call splitList
     * function .
     */
    struct node *fast = source->next ;
    
    /* When this loop ends then slow will be pointing to  middle element */
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next ;
        slow = slow->next ;
    }
    // Make backRef points to a new Sub-list
    (*backRef) = slow->next ;
    slow->next = NULL ;
    
    // Make frontRef point to new sub-list
    (*frontRef) = source ;
}

// Merges two sorted list into one big list .
struct node* mergeList(struct node* a , struct node* b)
{
    // If any one list is empty
    // then simply return the list
    // which is not empty

    if(a == NULL)return b;
    else if(b == NULL)return a ;
    
    // It helps in creating a new sorted list
    // and then retutn the new list to *headRef
    struct node *result = NULL ;
    
    // If value of first node of list 'a'
    // is greater than value of first
    // node of list 'b'
    if(a->data > b->data)
    {
          result = b ;
          
        // Call the mergeList function recursively
        // for remaining lists
        result->next = mergeList(a,b->next);
    }
    else
    {
        result->data = a->data ;
        result->next = mergeList(a->next , b) ;
    }
    return result ;
    
}


