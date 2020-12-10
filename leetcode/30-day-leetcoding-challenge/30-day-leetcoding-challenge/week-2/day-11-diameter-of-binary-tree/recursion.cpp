/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) ;
    int diameterUtil(TreeNode *root , int &answer) ;
};

int Solution :: diameterUtil(TreeNode *root , int &answer)
{
    int leftSubTree = 0 ;
    int rightSubTree = 0 ;
    
    if(root->left != NULL) leftSubTree = diameterUtil(root->left , answer) ;
    
    if(root->right != NULL) rightSubTree = diameterUtil(root->right , answer) ;
    
    // It helps to find the path length from one leaf to another
    // of inner sub-tree either left or right
    answer = max(answer , leftSubTree + rightSubTree);
    
    // return the maximum length path of either left sub tree
    // or right sub tree + 1
    return max(leftSubTree , rightSubTree) + 1;
    
}
/* Computes the diameter of binary tree with given root.  */
int Solution :: diameterOfBinaryTree(TreeNode* root)
{
    // If no tree exists then answer is zero.
    if(root==NULL) return 0 ;
    
    // This will store the maximum diameter of inner sub-tree
    int answer = 0 ;
    
    // Stores the path length of left subtree
    int leftSubTree = 0;
    
    // Stores the path length of right subtree
    int rightSubTree = 0;
    
    // If left sub-tree exists then call the utility function
    // to find length of path of left sub-tree
    if(root->left != NULL)
    leftSubTree = diameterUtil(root->left , answer) ;
    
    // If right sub-tree exists then call the utility function
    // to find length of path of right sub-tree
    if(root->right != NULL)
    rightSubTree = diameterUtil(root->right , answer) ;
    
    // The answer will be either path which contains the root
    // or the path which does not contain the root i.e sub-tree path
    return max(leftSubTree + rightSubTree  , answer) ;
}
