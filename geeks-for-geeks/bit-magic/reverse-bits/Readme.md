Why the answer is changing when i am changing the type of int ?
The reason being MSB of every number is reserved for sign bit either 0 or 1 .
And hence when we were setting last bit ON or OFF depending on last bit , due
to this last bit we were getting negative result and that's why we have to use
unsigned int . Moreover , the answer is also changing when we were using 
long long int , the reason being long long int is 64 bit long , due to which our
answer is getting changed .

Solution using -- 
1-- [int](https://ide.geeksforgeeks.org/K4H0Z4kZyK)
2 -- [unsigned int](https://ide.geeksforgeeks.org/jpNCnxBp2Z)
