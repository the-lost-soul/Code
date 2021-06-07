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
    vector<int> preorderTraversal(TreeNode* root) ;
    void helper(TreeNode* root , vector<int>& ans) ;
};

void Solution :: helper(TreeNode* root , vector<int>& ans)
{
    if(!root)return ;
    ans.push_back(root->val) ;
    helper(root->left , ans) ;
    helper(root->right , ans) ;
    
}

vector<int> Solution :: preorderTraversal(TreeNode* root)
{
    vector<int> ans ;
    helper(root , ans) ;
    return ans ;
}

