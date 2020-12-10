int helper(Node *root , int key , int &count)
{
    if(!root) return 0 ;
    
    
    int leftSum = helper(root->left , key , count) ;
    int rightSum = helper(root->right , key , count) ;
    
    if(leftSum + rightSum + root->data == key)count ++ ;
    
    return leftSum + rightSum + root->data ;
}
// your are required to complete this function
// function should return the count of the number of 
// subtrees with Sum equal to X
int countSubtreesWithSumX(Node* root, int x)
{
    int count = 0 ;
	helper(root , x , count) ;
	return count ;
    
}

