Do check validity of this solution ::

Perform an inorder traversal and then find the longest increasing sequence .
Since inorder traversal of a BST gives a sorted result . 

Won't work as in the question we want a subtree having leaf nodes too , which   is not possible in this solution .

Eg --  
       9
      /\
     /  \
    7    10
   / \
  /   \
 35    1

Ans as per Inorder logic : size == 3(7 , 9 , 10)
Correct ans : size == 1
