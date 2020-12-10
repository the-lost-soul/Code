Node *target(Node *root)
{
    // If no tree exists return NULL
    if(!root) return root ;
    
    while(root)
    {
        // If left or right sub-tree exists return that .
        if(root->left) return root->left ;
        else if(root->right) return root->right ;
    
        /* If both right and left childrens of current node doesn't exists ,
        * then move to next right of current node 
        */
        root = root->nextRight ;
    }
    
    return root ;
}

// Should set the nextRight for all nodes
// It works  for all types of binary tree .
void connect(Node *root)
{
    // If no tree exists
   if(!root) return ;
   
   // If left tree exists
   /* Connect the next and right pointers of left and right sub-tree respectively */
   if(root->left)
   root->left->nextRight = (root->right) ? root->right : target(root->nextRight) ;
   
   
   // If right sub-tree exists .
   /* Connect the next and left pointers of right and left sub-tree respectively */
   if(root->right)
   root->right->nextRight = target(root->nextRight) ;
   
   // Recursively call left and right sub-tree .
   connect(root->left) ;
   connect(root->right) ;
   
    
}
