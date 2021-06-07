class Solution:
    def numSubarrayBoundedMax(self, arr: List[int], lower: int, upper: int) -> int:
        left = right = ans = subArr = 0
        while(right < len(arr)) :
            if arr[right] >= lower and arr[right] <= upper :
                subArr = right - left + 1
            elif arr[right] > upper :
                subArr = 0
                left = right + 1
            
            ans += subArr
            right += 1
        return ans
