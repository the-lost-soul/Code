# The linear time solution won't work when array contains duplicates .
Eg -- 

      arr1 = [1 , 1 , 1 , 2 , 2 , 2] , 

      arr2 = [1 , 1 , 1 , 2 , 2 , 2] , 
      
      arr3 = [1 , 1 , 1 , 2 , 2 , 2]
      
As per question statement , output should be --

      [1 , 2]
      
Instead output comes out to be --

      [1 , 1 , 1 , 2 , 2 , 2]


 # NOTE --
 
 + But as in the question statement , it is written that arrays are strictly
   increasing hence they can't contain duplicates . So in leetcode the linear
   time solution will get accepted .
