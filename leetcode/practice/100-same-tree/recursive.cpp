class Solution {
public:
    bool isSameTree(TreeNode* tree1, TreeNode* tree2) ;
};

bool Solution :: isSameTree(TreeNode * tree1 , TreeNode * tree2)
{
    // If both tree does not exists , then both trees are same .
    if(!tree1 && !tree2)return true ;
    
    // If any one tree does not exists , then trees are not same .
    if((!tree1 && tree2) || (tree1 && !tree2))return false ;
    
    // If root of current sub-trees are equal then recursively check
    // for left and right sub-trees .
    if(tree1->val == tree2->val)return isSameTree(tree1->left , tree2->left)
                                        && isSameTree(tree1->right , tree2->right) ;
    
    // If not equal , then trees are not same .
    else return false ;
    
    
}
