class Solution:
    days = [31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31]
    def daysFrom1971(self , date : str) -> int :
        year = int(date[:4])
        month = int(date[5:7])
        day = int(date[8:])
        for y in range(1971 , year) :
            if (y%4 == 0 and (y%100 != 0 or y%400 == 0)) :
                day += 366
            else :
                day += 365
        
        if month > 2 and year%4 == 0 and (year%100 != 0 or year%400 == 0) :
            day += 1
        
        while month > 1 :
            month -= 1
            day += self.days[month - 1]
        return day
    def daysBetweenDates(self, date1: str, date2: str) -> int :
        return abs(self.daysFrom1971(date1) - self.daysFrom1971(date2))
        
        
        
