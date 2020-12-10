void postOrder(Node * root , Node * parent)
{
    if(!root)return ;
    
    postOrder(root->left , root) ;
    postOrder(root->right , root) ;
    
    if(parent->left == root)parent->left = NULL ;
    else parent->right = nullptr ;
    free(root) ;
}
Node * deleteHelper(Node * root , int key)
{
    Node * node = root->left ;
    if(root->data >= key)
    {
        postOrder(root->right , root) ;
    }
    root->right = root->left = nullptr ;
    free(root) ;
    
    return node ;
}
/*The function should return the root of the modified tree*/
Node* deleteNode(Node* root, int key)
{
    if(!root)return root ;
    if(root->data >= key)
    {
        Node * temp = deleteHelper(root , key) ;
        return deleteNode(temp , key) ;
    }
    else root->right = deleteNode(root->right , key) ;
    
}
