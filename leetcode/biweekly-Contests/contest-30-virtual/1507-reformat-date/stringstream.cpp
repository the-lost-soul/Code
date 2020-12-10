class Solution {
    unordered_map<string , string>hashMonth ;
public:
    string reformatDate(string date) ;
};

string Solution :: reformatDate(string date)
{
    hashMonth["Jan"] = "01" ;
    hashMonth["Feb"] = "02" , hashMonth["Mar"] = "03" , hashMonth["Apr"] = "04" , hashMonth["May"] = "05" , hashMonth["Jun"] = "06" ;
    hashMonth["Jul"] = "07" , hashMonth["Aug"] = "08" , hashMonth["Sep"] = "09" , hashMonth["Oct"] = "10" , hashMonth["Nov"] = "11" ;
    hashMonth["Dec"] = "12" ;
    stringstream ss(date) ;
    string day , month , year ;
    ss >> day ;
    ss >> month ;
    ss >> year ;
    
    while(islower(day[day.size() - 1]))day.pop_back() ;
    if(day.size() == 1)day = "0" + day ;
    
    return year + "-" + hashMonth[month] + "-" + day ;
    
}
