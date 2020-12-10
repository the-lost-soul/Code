/* THIS WILL WORK ONLY WHEN LIST IS SORTED IN BOTH DIRECTION */

/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{
    
    // If right Linked List is not present
    // then answer is bottom linked list
    if(root->next == NULL)return root ;
    
    Node *temp ;
    Node *head = (Node *)malloc(sizeof(Node)) ;
    head->data = root->data ;
    
    // It is NULL because in print function the flattened
    // list is called using bottom variable
    head->next = NULL ;
    
    // If bottom linked list is not present
    // Then function will be called 
    // For right linked list
    
    if(root->bottom == NULL)
    {
        temp = root ;
        root = root->next ;
        free(temp) ;
    }
    
    // If bottom data is less than right data
    
    else if(root->bottom->data <= root->next->data)
    {
        root->bottom->next = root->next ;
        temp = root->bottom ;
        delete root ;
        root = temp ;
    }
    
    // If bottom data is greater than right data
    // then traverse the right list until we find 
    // a suitable position for bottom linked list
    else
    {
        Node *bottomTraverse = root->bottom ;
        Node *rightTraverse = root->next ;
        while(rightTraverse->next != NULL)
        {
            // If bottom data lies in between right data and 
            // next of right data then we have found the position
            // so insert the bottom linked list in between both
            // and break
            if(bottomTraverse->data > rightTraverse->data
            && bottomTraverse->data <= rightTraverse->next->data)
            {
                bottomTraverse->next = rightTraverse->next ;
                rightTraverse->next = bottomTraverse ;
                break ;
            }
            // if we aren't able to find any suitable position
            // then add the bottom list to last of right list
            else if(rightTraverse->next == NULL)
            {
                rightTraverse->next = bottomTraverse ;
            }
            else rightTraverse = rightTraverse->next ;
        }
        temp = root->next ;
        delete root ;
        root = temp ;
    }
    
    // Call for remaining list to be flattened
    head->bottom = flatten(root) ;
    return head ;
    
}
