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
    vector<int>inorder ;
public:
    void solve(TreeNode* root)
    {
        if(root->left)
            solve(root->left) ;
        inorder.push_back(root->val) ;
        if(root->right)
            solve(root->right) ;
    }

    TreeNode* increasingBST(TreeNode* root)
    {
        solve(root) ;
        TreeNode* new_root = NULL , *node , *prev = NULL ;
        for(auto ele : inorder)
        {
            node = new TreeNode(ele) ;
            if(!prev)
            {
                prev = node ;
                new_root = node ;
            }
            else
            {
                prev->right = node ;
                prev = node ;
            }
        }
        return new_root ;
    }
};
