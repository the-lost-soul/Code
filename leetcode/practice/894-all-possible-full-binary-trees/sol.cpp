/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode* clone(TreeNode* root)
    {
        TreeNode* new_root = new TreeNode(0) ;
        new_root->left = root->left ? clone(root->left) : nullptr ;
        new_root->right = root->right ? clone(root->right) : nullptr ;
        return new_root ;
    }

    vector<TreeNode*> allPossibleFBT(int n)
    {
        vector<TreeNode*> ans ;
        if(n == 1)
           ans.push_back(new TreeNode(0)) ; 
        else if(n%2)
        {
            for(int i = 1 ; i < n ; i += 2)
            {
                vector<TreeNode*> leftSubTree = allPossibleFBT(i) ;
                vector<TreeNode*> rightSubTree = allPossibleFBT(n - i - 1) ;

                for(int i = 0 ; i < leftSubTree.size() ; i++)
                {
                    for(int j = 0 ; j < rightSubTree.size() ; j++)
                    {
                        TreeNode* root = new TreeNode(0) ;
                        // cloning each sub tree so that each tree
                        // can be unique .
                        TreeNode* leftClonedTree = leftSubTree[i] ;
                        TreeNode* rightClonedTree = rightSubTree[j] ;
                        // Instead of cloning last tree , we simply
                        // utilize it as it will presist in the memory .
                        // and since its last so there won't be any
                        // copy of this sub-tree .
                        if(i < leftSubTree.size() - 1)
                            leftClonedTree = clone(leftSubTree[i]) ;
                        if(j < rightSubTree.size() - 1)
                            rightClonedTree = clone(rightSubTree[j]) ;
                        root->left = leftClonedTree ;
                        root->right = rightClonedTree ;
                        ans.push_back(root) ;
                    }
                }
            }
        }
        return ans ;
    }
};
