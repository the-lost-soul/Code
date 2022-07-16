class Solution
{
    public int romanToInt(String s)
    {
        HashMap<Character , Integer> roman = new HashMap<>() ;
        roman.put('I' , 1) ;
        roman.put('V' , 5) ;
        roman.put('X' , 10) ;
        roman.put('L' , 50) ;
        roman.put('C' , 100) ;
        roman.put('D' , 500) ;
        roman.put('M' , 1000) ;
        int ans = 0 ;
        for(int i = s.length() - 1 ; i >= 0 ; i--)
        {
            if(i < s.length() - 1 && roman.get(s.charAt(i)) < roman.get(s.charAt(i + 1)))
                    ans -= roman.get(s.charAt(i)) ;
            else
                ans += roman.get(s.charAt(i)) ;
        }
        return ans ;
    }
}
