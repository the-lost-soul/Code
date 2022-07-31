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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) ;
    void inOrder(TreeNode* root , vector<int>& tree) ;
    vector<int> merge(vector<int>tree1 , vector<int>tree2) ;
};

vector<int> Solution :: merge(vector<int> tree1 , vector<int> tree2)
{
    vector<int> ans ;
    int i = 0 , j = 0 ;
    while(i < tree1.size() and j < tree2.size())
    {
        if(tree1[i] <= tree2[j])
        {
            ans.push_back(tree1[i]) ;
            i++ ;
        }
        else
        {
            ans.push_back(tree2[j]) ;
            j++ ;
        }
    }
    
    while(i < tree1.size())
    {
        ans.push_back(tree1[i]) ;
        i++ ;
    }
    while(j < tree2.size())
    {
        ans.push_back(tree2[j]) ;
        j++ ;
    }
    return ans ;
}
void Solution :: inOrder(TreeNode* root , vector<int>& tree)
{
    if(!root)return ;
    inOrder(root->left , tree) ;
    tree.push_back(root->val) ;
    inOrder(root->right , tree) ;
    
}
vector<int> Solution :: getAllElements(TreeNode* root1 , TreeNode* root2)
{
    vector<int>tree1 ;
    inOrder(root1 , tree1) ;
    vector<int>tree2 ;
    inOrder(root2 , tree2) ;
    return merge(tree1 , tree2) ;
}
