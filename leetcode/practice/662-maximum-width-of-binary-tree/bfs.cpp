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
    int widthOfBinaryTree(TreeNode* root)
    {
        if(!root)
            return 0 ;

        int res = 1 ;

        queue<pair<TreeNode* , long long int>>q ;
        q.push({root , 0}) ;

        while(!q.empty())
        {
            int len = q.size() ;

            int start = 0 , end = 0 ;
            for(int i = 0 ; i < len ; i++)
            {
                if(i == 0)
                    start = q.front().second ;
                if(i == len - 1)
                    end = q.front().second ;

                pair<TreeNode* , long long int>currNode = q.front() ;
                q.pop() ;
                int idx = currNode.second - start ;

                if(currNode.first->left != NULL)
                    q.push({currNode.first->left ,(long long) 2*idx + 1}) ;

                if(currNode.first->right != NULL)
                    q.push({currNode.first->right , (long long)2*idx + 2}) ;
            }

            res = max(res , end -  start + 1) ;
        }

        return res ;
    }
};
