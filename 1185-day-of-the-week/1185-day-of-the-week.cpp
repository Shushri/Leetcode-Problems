class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        vector<string> daY = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
        vector<int> daysOfMonth = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        if( leapYear(year) ){
            daysOfMonth[2] = 29; // Feb has 29 days if it is a leap year
        }
        int daysOfYear = 4; //31st December 1970 is Thursday, so intialize as 4

        //Add the days of the previous years
        for( int i = 1971 ; i < year ; i++){
            if( leapYear(i)){
                daysOfYear += 366;
            }else{
                daysOfYear += 365;
            }
        }
        //Add the days of the previous months
        for( int i = 1 ; i < month ; i++){
            daysOfYear += daysOfMonth[i];
        }
        daysOfYear += day; //Add the current day
        return daY[daysOfYear % 7]; //Modulo divide by 7 to find odd days
    }
    bool leapYear(int year){
        if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            return true;
        return false; 
    }
};