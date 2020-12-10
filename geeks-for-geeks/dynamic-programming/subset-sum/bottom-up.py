#code

def solve(arr , size) :
    total_sum = sum(arr)
    if total_sum%2 != 0 : return "NO"
    dp = [[False for j in range(total_sum//2 + 1)] for i in range(size + 1)]
                    
    for i in range(size + 1) :
        dp[i][0] = True

    for i in range(total_sum//2 + 1) :
        dp[0][i] = False
    
    for i in range(1 , size + 1) :
        for j in range(1 , total_sum//2 + 1) :
            if arr[i - 1] > j : dp[i][j] = dp[i - 1][j]
            else : dp[i][j] = dp[i - 1][j] or dp[i - 1][j - arr[i - 1]]
    
    return "YES" if dp[size][total_sum//2] == True else "NO"


testcases = int(input())
for i in range(testcases) :
    size = int(input())
    arr = []
    # for j in range(size) :
    arr = list(map(int , input().split()))
    print(solve(arr , size))
