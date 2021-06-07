# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        ans = 1
        def helper(node) :
            nonlocal ans
            if not node : return 0
            left = helper(node.left)
            right = helper(node.right)
            ans = max(left + right + 1 , ans)
            return max(left , right) + 1
        helper(root)
        return ans - 1
        
