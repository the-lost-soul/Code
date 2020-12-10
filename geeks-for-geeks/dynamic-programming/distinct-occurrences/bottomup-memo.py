def sequenceCount(source , target) :
    m = len(target)
    n = len(source)
    if m > n :
        return 0
    
    dp = [[0 for i in range(0 , n + 1)] for j in range(0 , m + 1)]
    for i in range(m + 1) :
        dp[i][0] = 0
    for i in range(n + 1) :
        dp[0][i] = 1
    
    for i in range(1 , m + 1) :
        for j in range(1 , n + 1) :
            if source[j - 1] != target[i - 1] :
                dp[i][j] = dp[i][j - 1]
            else :
                dp[i][j] = dp[i -1][j - 1] + dp[i][j - 1]
    return (dp[m][n])%(1000000007)
