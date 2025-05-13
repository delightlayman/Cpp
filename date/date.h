#include <iostream>
using std::ostream;
using std::istream;
using std::cin;
using std::cout;
using std::endl;
class Date{
private:
    int _year;
    int _month;
    int _day;
public:
    //至今天数
    int UpToNow_acc()const;
    int UpToNow()const;


    //每月天数
    int GetMonthDays(int year,int month)const;
    //构造
    Date(int year,int month,int day);
    //拷贝构造
    Date(const Date& d);
    //析构函数
    ~Date();
    
    //运算符重载=
    Date& operator=(const Date& d);
    bool operator==(const Date& d);
    bool operator!=(const Date& d);
    bool operator>(const Date& d);
    bool operator<(const Date& d);
    bool operator<=(const Date& d);
    bool operator>=(const Date& d);
    
    //加减天数
    Date& operator+=(int day);
    Date& operator-=(int day);
    Date operator+(int day);
    Date operator-(int day);
    
    //日期相减
    int operator-(const Date& d);

    //++，--
    //前缀形式
    Date& operator++();
    Date& operator--();
    //后缀
    Date operator++(int);
    Date operator--(int);


    friend ostream& operator<<(ostream& cout,const Date& d);
    friend istream& operator>>(istream& cin,Date& d);
        

};