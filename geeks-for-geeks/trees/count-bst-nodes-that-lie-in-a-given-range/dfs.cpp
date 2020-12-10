void helper(Node* root , int l , int h , int& count)
{
    if(!root)
    {
        return ;
    }
    
    if(l <= root->data and h >= root->data)count++ ;
    if(root->data >= l)helper(root->left , l , h , count) ;
    if(root->data <= h)helper(root->right , l , h , count) ;
}
int getCountOfNode(Node *root, int l, int h)
{
    int count = 0 ;
    helper(root , l , h , count) ;
    return count ;
}
