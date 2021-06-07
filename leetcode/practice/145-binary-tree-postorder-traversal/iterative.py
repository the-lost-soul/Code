# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        res , stack = [] , [(root , False)]
        node = root
        while stack :
            node , visited = stack.pop()
            if node :
                if visited :
                    res.append(node.val)
                else :
                    stack.append((node , True))
                    stack.append((node.right , False))
                    stack.append((node.left , False))
                    
        return res
                    
                    
            
