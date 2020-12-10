int helper(Node *root , int key , int &count)
{
    if(!root) return 0 ;
    
    
    int leftSum = helper(root->left , key , count) ;
    int rightSum = helper(root->right , key , count) ;
    
    if(leftSum + rightSum + root->data == key) count ++ ;
    
    return leftSum + rightSum + root->data ;
}
// your are required to complete this function
// function should return the count of the number of 
// subtrees with Sum equal to X
int countSubtreesWithSumX(Node* root, int x)
{
    if(!root)return 0 ;
    
    int count = 0 ;
    
    // This will find the sum of all sub-tree except root .
	int leftSum = helper(root->left , x , count) ;
	int rightSum = helper(root->right , x , count) ;
	
	if(leftSum + rightSum + root->data == x)count ++ ;
	
	return count ;
    
}
