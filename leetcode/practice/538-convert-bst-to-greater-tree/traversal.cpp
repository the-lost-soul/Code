class Solution {
    int sum ;
public:
    void solve(TreeNode* root)
    {
        if(!root)
            return ;

        solve(root->right) ;
        root->val += sum ;
        sum = root->val ;
        solve(root->left) ;
    }
    TreeNode* convertBST(TreeNode* root)
    {
        sum = 0 ;
        solve(root) ;
        return root ;
    }
};
