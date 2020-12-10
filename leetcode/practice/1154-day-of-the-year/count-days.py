class Solution:
    def dayOfYear(self, date: str) -> int:
        days = [31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31] ;
        year = int(date[:4])
        month = int(date[5:7])
        day = int(date[8:])
        
        leap = year%400 == 0 or (year%4 == 0 and year%100 != 0)
        ans = 0
        if month > 2 and leap :
            ans += 1
        for m in range(month - 1) :
            ans += days[m]
        
        ans += day
        return ans
