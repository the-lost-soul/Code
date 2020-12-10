void helper(Node *root , Node **head)
{
    // It keeps track of previously visited node .
    // It is static so that we can access the same value
    // in all recursive calls and also the value of prev 
    // cjanges after each recursive calls and this change
    // is reflected in all the recursive calls .
    static Node *prev = NULL ;
    
    // Recursively call for left sub-tree
    if(root->left != NULL)
    helper(root->left , head) ;
    
    
    // If DLL is empty , then make the head point to
    // root
    if(*head == NULL)
    {
        *head = root ;
        
        // Working fine
        // cout<<"aquib";
    }
    
    /* If DLL is not empty then do following-->>
       1. Make the previously visited node point
       to the newly visited node(i.e root) via right .
       
       2. Make the newly visited node point to previous
       node via left .
    */
    else
    {
        root->left = prev;
        prev->right = root ;
    }
    
    
    // Make the newly visited node of tree as prev
    // as we have done all work related to this .
    prev = root ;
    
    // Working fine
    // cout<<(*head)->data<<endl;
    
    
    // Recursively call for right sub-tree
    if(root->right != NULL)
    helper(root->right, head) ;
}

// This function should convert a given Binary tree to Doubly
// Linked List
// root --> Root of Binary Tree
// head_ref --> Pointer to head node of created doubly linked list

void BToDLL(Node *root, Node **head_ref)
{
    // Node *prev = NULL ;
    helper(root , head_ref) ;
    // Node *head = *head_ref ;
    /*
    while(head != NULL)
    {
        cout<<head->data<<" ";
        head = head->right;
    }
    cout<<endl ;
    */
    
}
