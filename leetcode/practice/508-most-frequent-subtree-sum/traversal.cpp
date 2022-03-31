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
class Solution {
    int frequency ;
    unordered_map<int , int>hash ;
public:
    int solve(TreeNode* root)
    {
        if(!root)
            return 0 ;
        int left = solve(root->left) ;
        int right = solve(root->right) ;
        int total = root->val + left + right ;
        hash[total]++ ;
        frequency = max(hash[total] , frequency) ;
        return total ;
    }

    vector<int> findFrequentTreeSum(TreeNode* root)
    {
        frequency = INT_MIN ;
        int temp = solve(root) ;

        vector<int> ans ;
        for(auto ele : hash)
            if(ele.second == frequency)
                ans.push_back(ele.first) ;
        return ans ;
    }
};
