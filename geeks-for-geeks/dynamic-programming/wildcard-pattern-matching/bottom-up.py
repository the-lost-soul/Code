def wildCard(text , pattern) :
    textLen = len(text) 
    pattLen = len(pattern)
    
    dp = [[False for j in range(0 , pattLen + 1)] for i in range(0 , textLen + 1)]
    dp[0][0] = True
    
    for i in range(1 , pattLen + 1) :
        if pattern[i - 1] == '*' :
            dp[0][i] = dp[0][i - 1]
    
    for i in range(1 , textLen + 1) :
        for j in range(1 , pattLen + 1) :
            if pattern[j - 1] == '*' :
                dp[i][j] = dp[i - 1][j] or dp[i][j - 1]
            
            if pattern[j - 1] == '?' or pattern[j - 1] == text[i - 1] :
                dp[i][j] = dp[i - 1][j - 1]
    
    return dp[textLen][pattLen]
    
    
