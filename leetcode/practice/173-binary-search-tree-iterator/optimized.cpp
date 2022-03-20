class BSTIterator
{
    stack<TreeNode*>tree ;
public:
    BSTIterator(TreeNode* root)
    {
        findLeft(root) ;
    }
    
    int next()
    {
        TreeNode* node = tree.top() ;
        tree.pop() ;
        if(node->right != nullptr)
        {
            findLeft(node->right) ;
        }
        return node->val ;
    }
    
    bool hasNext()
    {
        return !tree.empty() ;
    }

    void findLeft(TreeNode* root)
    {
        TreeNode* node = root ;
        while(node != nullptr)
        {
            tree.push(node) ;
            node = node->left ;
        }
    }
};
