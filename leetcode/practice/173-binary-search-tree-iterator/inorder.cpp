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
class BSTIterator
{
    vector<int>inorder ;
    int idx ;
public:
    void solve(TreeNode* root)
    {
        if(!root)
            return ;
        
        solve(root->left) ;
        inorder.push_back(root->val) ;
        solve(root->right) ;
    }
    BSTIterator(TreeNode* root)
    {
        solve(root) ;
        idx = -1 ;
    }
    
    int next()
    {
        idx++ ;
        return inorder[idx] ; 
    }
    
    bool hasNext()
    {
        return idx + 1 < inorder.size() ? true : false ;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
