def mergeInit(arr , n) :
    tempArr = [0]*n 
    return mergeSort(arr , tempArr , 0 , n - 1)
    
def mergeSort(arr , temp , start , end) :
    invCount = 0 
    if(start < end) :
        mid = (start + end)//2 ;
        invCount = mergeSort(arr , temp , start , mid)
        invCount += mergeSort(arr , temp , mid + 1 , end)
        invCount += merge(arr , temp , start , mid + 1 , end)
    
    return invCount ;

def merge(arr , temp , start , mid , end) :

    invCount = 0 
    middle = mid
    tempIndex = start
    while tempIndex < mid and middle <= end :
        if arr[tempIndex] > arr[middle] :
            temp[tempIndex] = arr[middle]
            invCount += mid - tempIndex + 1
            middle += 1
            tempIndex += 1
        else :
            temp[tempIndex] = arr[start]
            tempIndex += 1
            start += 1
    
    while tempIndex < mid :
        temp[tempIndex] = arr[tempIndex]
        tempIndex += 1
    
    while middle < end :
        temp[middle] = arr[middle]
        middle += 1
    
    for i in range(start , end + 1) :
        arr[i] = temp[i]
        
    return invCount        

testcase = input()
for i in range(int(testcase)) :
    size = int(input())
    arr = input()
    arr = list(map(int,arr.split(' ')))
    result = mergeInit(arr , size)
    print(result)
    print("")
