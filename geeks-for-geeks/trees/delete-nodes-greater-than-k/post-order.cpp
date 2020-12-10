/*The function should return the root of the modified tree*/
/* The idea is to use post Order Traversal and delete the
 * nodes whose value is greater than key .
 */
Node * deleteNode(Node * root , int key)
{
    if(!root)return root ;
    
    root->left = deleteNode(root->left , key) ;
    root->right = deleteNode(root->right , key) ;
    
    if(root->data >= key)
    {
        Node * temp = NULL ;
        if(root->left)temp = root->left ;
        else temp = root->right ;
        free(root) ;
        return temp ;
    }
    return root ;
}
