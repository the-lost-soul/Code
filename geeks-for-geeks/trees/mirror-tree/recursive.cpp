/* The idea is first call left sub-tree and then call right sub-tree
and then interchange the location of nodes */

void mirrorUtil(Node *root)
{
    if(root->left != NULL)
    mirrorUtil(root->left);
    
    
    if(root->right != NULL)
    mirrorUtil(root->right);
    
    Node *temp;
    temp = root->left;
    root->left = root->right;
    root->right = temp;

}
/* Should convert tree to its mirror */
void mirror(Node* root) 
{
    mirrorUtil(root);
    
    
    
}

