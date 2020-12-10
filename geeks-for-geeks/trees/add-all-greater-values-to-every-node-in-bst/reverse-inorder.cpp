void helper(Node * root , int & sum)
{
    // Stores the current sum ;
    int temp ;
    if(!root)return ;
    
    // Doing a reverse inOrder traversal .
    helper(root->right , sum) ;
    temp = sum ;
    sum += root->data ;
    root->data += temp ;
    
    helper(root->left , sum) ;
}
/*  modifies the root of the bst */
void modify(Node **root)
{
    int sum = 0 ;
    helper(*root , sum) ;
}
