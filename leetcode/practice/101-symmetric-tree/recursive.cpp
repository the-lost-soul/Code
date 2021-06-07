class Solution {
public:
    bool isSymmetricUtil(TreeNode *root1 , TreeNode *root2)
    
        // If both left and right sub-tree is not present then return true
        if(root1 == NULL && root2 == NULL)return true;
        
        // If any one of left or right sub-tree is absent and one is present
        // then return false i.e tree is not symmetric
        if(root1 == NULL || root2 == NULL)return false;
        
        //Here two case arises for tree to be not symmetric
        // 1. if value of roots of both sub-trees are not equal
        // 2. If value returned by helper function is false
        return (root1->val == root2->val) && (isSymmetricUtil(root1->left , root2->right)
         && isSymmetricUtil(root1->right , root2->left));
        
    
    
    bool isSymmetric(TreeNode* root) 
    
        // If empty tree then tree is symmetric
        if(root == NULL)return true;
        
        return isSymmetricUtil(root->left , root->right);
    
};
