void helper(Node *root , Node **head)
{
    if(root == NULL) return ;
    
    // Recursively call right sub-tree
    helper(root->right , head) ;
    
    // Link the new node with old node of DLL
    root->right = *head ;
    
    // If length of DLL is one , then *head will
    // be NULL whereas if we have processed some node
    // i.e length of node is greater than 1 , then that 
    // means *head contains the address of previously
    // visited node , so link that previous node with
    // new node using " LEFT "
    if(*head != NULL)
    {
        (*head)->left = root ;
    }
    
    // Make the new node as head
    *head = root ;
    
    // Recursively call for left sub-tree
    helper(root->left , head) ;
    
}

// This function should convert a given Binary tree to Doubly
// Linked List
// root --> Root of Binary Tree
// head_ref --> Pointer to head node of created doubly linked list

void BToDLL(Node *root, Node **head_ref)
{
    helper(root , head_ref) ;
    
}
