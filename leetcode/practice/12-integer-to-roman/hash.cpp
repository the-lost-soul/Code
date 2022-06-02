class Solution
{
    vector<int>numbers = {1 , 4 , 5 , 9 , 10 ,
                            40 , 50 , 90 , 100 , 400 ,
                            500 , 900 , 1000 } ;
    vector<string>roman = {"I" , "IV" , "V" , "IX" , "X" ,
                            "XL" , "L" , "XC" , "C" , "CD" ,
                            "D" , "CM" , "M" } ;


public:
    string intToRoman(int num)
    {
        string ans = "" ;
        for(int i = 12 ; num != 0 ; i--)
        {
            while(num >= numbers[i])
            {
                num -= numbers[i] ;
                ans += roman[i] ;
            }
        }
        return ans ;
    }
};
