class Solution {
public:
    vector<int> rightSideView(TreeNode* root)
    {
        if(!root)return {} ;
        vector<int>ans ;
        queue<TreeNode*>level ;
        level.push(root) ;
        level.push(nullptr) ;
        while(!level.empty())
        {
            TreeNode* node = level.front() ;
            level.pop() ;
            if(node->left) level.push(node->left) ;
            if(node->right) level.push(node->right) ;

            if(level.front() == nullptr)
            {
                level.pop() ;
                ans.push_back(node->val) ;
                if(level.empty())break ;
                level.push(nullptr) ;
            }
        }
        return ans ;
    }
};
