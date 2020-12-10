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
    vector<int> postorderTraversal(TreeNode* root) ;
    void helper(TreeNode* root , vector<int>& ans) ;
};

void Solution :: helper(TreeNode* root , vector<int>& ans)
{
    if(!root)return ;
    helper(root->left , ans) ;
    helper(root->right , ans) ;
    ans.push_back(root->val) ;
}

vector<int> Solution :: postorderTraversal(TreeNode* root)
{
    vector<int> ans ;
    helper(root , ans) ;
    return ans ;
}



