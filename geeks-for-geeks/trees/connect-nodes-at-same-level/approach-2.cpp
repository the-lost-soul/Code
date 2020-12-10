// Should set the nextRight for all nodes
// It works only for complete binary tree .
void connect(Node *root)
{
    // If no tree exists
   if(!root) return ;
   
   // If left tree exists
   /* Connect the next and right pointers of left and right sub-tree respectively */
   if(root->left)
   root->left->nextRight = root->right ;
   
   
   // If right sub-tree exists .
   /* Connect the next and left pointers of right and left sub-tree respectively */
   if(root->right)
   root->right->nextRight = (root->nextRight) ?root->nextRight->left:nullptr ;
   
   // Recursively call left and right sub-tree .
   connect(root->left) ;
   connect(root->right) ;
   
    
}
