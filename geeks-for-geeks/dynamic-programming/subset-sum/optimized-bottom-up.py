#code

def solve(arr , size) :
    total_sum = sum(arr)
    if total_sum%2 != 0 : return "NO"
    dp = [[False for j in range(total_sum//2 + 1)] for i in range(3)]
                    
    for i in range(size + 1) :
        for j in range(total_sum//2 + 1) :
            if i == 0 : dp[0][j] = False
            elif j == 0 : dp[i%2][0] = True
            elif arr[i - 1] > j : dp[i%2][j] = dp[(i - 1)%2][j]
            else : dp[i%2][j] = dp[(i - 1)%2][j] or dp[(i - 1)%2][j - arr[i - 1]]
    
    return "YES" if dp[size%2][total_sum//2] == True else "NO"


testcases = int(input())
for i in range(testcases) :
    size = int(input())
    arr = []
    # for j in range(size) :
    arr = list(map(int , input().split()))
    print(solve(arr , size))
