#include "date.h"


    //至今天数
    int Date::UpToNow_acc()const{
        Date tmp(*this);
        int sum=tmp._day;
        while(tmp._year>0){
            --tmp._month;
            if (tmp._month == 0) {
                --tmp._year;
                if(!tmp._year) return sum;
                tmp._month = 12;
            }
            sum+=GetMonthDays(tmp._year,tmp._month);   
        }
        return sum;
    }
    int Date::UpToNow()const{
        Date tmp(*this);
        int sum=tmp._day;
        while(tmp._month>0){
            --tmp._month;
            if (!tmp._month) 
                break;
            sum+=GetMonthDays(tmp._year,tmp._month);   
        }
        int pre_year=tmp._year-1;
        sum+=pre_year/4-pre_year/100+pre_year/400+pre_year*365;
        return sum;
    }


    //每月天数
    int Date::GetMonthDays(int year,int month)const{
        if(year<=0||month<=0||month>12){
            printf("invalid Date data");
            exit(-1);
        }
        int month_days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};//对应1-12月，无0月
        //闰年
        if((year%4==0&&year%100!=0)||year%400==0)
            month_days[2]=29;
        return month_days[month];        
    }
    //构造
    Date::Date(int year=1,int month=1,int day=1){
        if(year<=0||month<1||month>12||day<1){
            printf("invalid Date data");
            exit(-1);
        }
        _year=year;
        _month=month;
        _day=day;
    }
    //拷贝构造
    Date::Date(const Date& d){
        _year=d._year;
        _month=d._month;
        _day=d._day;
    }
    //析构函数
    Date::~Date(){}
    //运算符重载=
    Date& Date::operator=(const Date& d){
        _year=d._year;
        _month=d._month;
        _day=d._day;    
        return *this;  
    }
    bool Date::operator==(const Date& d){
        return _year==d._year
            &&_month==d._month
            &&_day==d._day;  
    }
    bool Date::operator!=(const Date& d){
        return !(*this==d);  
    }
    bool Date::operator>(const Date& d){
        if(_year>d._year)
            return 1;
        else if(_year==d._year&&_month>d._month)
            return 1;
        else if(_year==d._year&&_month==d._month&&_day>d._day)
            return 1;     
        return 0;  
    }
    bool Date::operator<(const Date& d){
        // if(_year<d._year)
        //     return 1;
        // else if(_year==d._year&&_month<d._month)
        //     return 1;
        // else if(_year==d._year&&_month==d._month&&_day<d._day)
        //     return 1;     
        // return 0;  

        return !(*this==d||*this>d);
    }
    bool Date::operator<=(const Date& d){
        return *this==d||*this<d;
    }
    bool Date::operator>=(const Date& d){
        return *this==d||*this>d;
    }
    //加减天数
    Date& Date::operator+=(int day){
        if(day<0)
            return *this-=-day;
        _day+=day;
        while(_day>GetMonthDays(_year,_month)){
            _day-=GetMonthDays(_year,_month); 
            ++_month;
            if(_month>12)
                ++_year;   
        }
        return *this;
    }

    Date& Date::operator-=(int day){
        if(day<0)
            return *this+=-day;
        _day-=day;
        while(_day<0){
            --_month;
            _day+=GetMonthDays(_year,_month); 
            if(_month==0){
                --_year;
                _month=12;
            }       
        }
        return *this;
    }
    
    Date Date::operator+(int day){
        Date temp(*this);
        return temp+=day;
    }
    Date Date::operator-(int day){
        Date temp(*this);
        return temp-=day;
    }
    //日期相减
    int Date::operator-(const Date& d){
        int a=UpToNow();
        int b=d.UpToNow();
        return a-b;
    }

    //++，--
    //前缀形式
    Date& Date::operator++(){
        return *this+=1;
    }
    Date& Date::operator--(){
        return *this-=1;
    }
    //后缀
    Date Date::operator++(int){
        Date temp(*this);
        *this+=1;
        return temp;
    }
    Date Date::operator--(int){
        Date temp(*this);
        *this-=1;
        return temp;
    }


    ostream& operator<<(ostream& cout,const Date& d){
        cout<<d._year<<"-"<<d._month<<"-"<<d._day<<endl;
        return cout;
    }   

    istream& operator>>(istream& cin,Date& d){
        cin>>d._year>>d._month>>d._day;
        return cin;
    }
