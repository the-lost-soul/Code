int maxPathSumUtil(struct Node *root , int &answer)
{
    if(!root) return 0 ;
    
    int leftSubTree = 0 ;
    int rightSubTree = 0 ;
    
    if(root->left)leftSubTree = maxPathSumUtil(root->left , answer) ;
    if(root->right)rightSubTree = maxPathSumUtil(root->right , answer) ;
    
    answer = max(answer , leftSubTree + rightSubTree + root->data) ;
    return max(leftSubTree , rightSubTree) + root->data ;
    
}

int maxPathSum(struct Node * root)
{
    int answer = 0 ;
    maxPathSumUtil(root , answer) ;
    return answer ;
    
}
