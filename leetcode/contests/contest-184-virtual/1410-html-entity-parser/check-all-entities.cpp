class Solution {
public:
    string entityParser(string text) ;
};

string Solution :: entityParser(string text)
{
    string ans = "" ;
    int i = 0 ;
    while(i < text.length())
    {
        string specialChar = "" ;
        if(text[i] == '&')
        {
            specialChar += text[i] ;
            i++ ;
            while(i < text.length() and text[i] != ';' and text[i] != ' ')
            {
                specialChar += text[i] ;
                i++ ;
            }
            if(text[i] == ';')
            {
                specialChar += text[i] ;
                i++ ;
            }
            if(specialChar == "&amp;")
            {
                ans += '&' ;
            }
            else if(specialChar == "&apos;")
            {
                ans += "'" ;
            }
            else if(specialChar == "&quot;")
            {
                ans += '"' ;
            }
            else if(specialChar == "&gt;")
            {
                ans += '>' ;
            }
            else if(specialChar == "&lt;")
            {
                ans += '<' ;
            }
            else if(specialChar == "&frasl;")
            {
                ans += '/' ;
            }
            else
                ans += specialChar ;
        }
        else
        {
            ans += text[i] ;
            i++ ;
        }
    }
    return ans ;
}
