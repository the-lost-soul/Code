# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        self.res = []
        def helper(root) :
            if not root : return 
            helper(root.left)
            self.res.append(root.val)
            helper(root.right)

        helper(root)
        return self.res
        
