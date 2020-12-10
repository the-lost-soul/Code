def solve(eggs , floors) :
    dp = [[0 for j in range(0 , floors + 1)] for i in range(0 , eggs + 1)]
    
    for i in range(eggs + 1) :
        dp[i][1] = 1 
        dp[i][0] = 0

    for i in range(floors + 1) :
        dp[1][i] = i


    for egg in range(2 , eggs + 1) :
        for flr in range(2 , floors + 1) :
            dp[egg][flr] = float('inf')
            for x in range(1 , flr + 1) :
                res = 1 + max(dp[egg - 1][x - 1] , dp[egg][flr - x])
                dp[egg][flr] = min(dp[egg][flr] , res)
    return dp[eggs][floors]
    
    
testcases = int(input())
for i in range(testcases):
    eggs , floors = input().split()
    eggs = int(eggs)
    floors = int(floors)
    print(solve(eggs , floors))


