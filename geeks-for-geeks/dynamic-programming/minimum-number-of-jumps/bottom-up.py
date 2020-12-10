#code
def solve(arr , size) :
    jumps = [float('inf')]*size
    if size == 0 or arr[0] == 0 : return -1
    jumps[0] = 0
    for i in range(1 , size) :
        for j in range(0 , i) :
            if i <= j + arr[j] and jumps[j] != float('inf') :
                jumps[i] = min(jumps[i] , jumps[j] + 1)
    return -1 if jumps[size - 1] == float('inf') else jumps[size - 1]


testcases = int(input())
for i in range(testcases) :
    size = int(input())
    arr = []
    arr = list(map(int , input().split()))
    print(solve(arr , size))
