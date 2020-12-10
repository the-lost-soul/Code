void helper(Node * root , int currLevel , int & maxLevel)
{
    if(!root)return ;
    if(currLevel > maxLevel)
    {
        cout<<root->data<<" " ;
        maxLevel = currLevel ;
    }
    helper(root->right , currLevel + 1 , maxLevel) ;
    helper(root->left , currLevel + 1 , maxLevel) ;
}
// Should print right view of tree
void rightView(Node *root)
{
    int currLevel = 0 ;
    int maxLevel = -1 ;
    helper(root , currLevel , maxLevel) ;
    
}
