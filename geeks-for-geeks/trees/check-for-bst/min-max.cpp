bool helper(Node * root , int min , int max)
{
    if(!root)return true ;
    
    if(root->data < min || root->data > max)return false ;
    
    return helper(root->left , min , root->data) and helper(root->right , root->data , max) ;
}
bool isBST(Node* root) 
{
    return helper(root , INT_MIN , INT_MAX) ;
}
