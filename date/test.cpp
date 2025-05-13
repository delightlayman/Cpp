#include "date.h"


// inline int swap(int& a,int& b){
//     int tmp=a;
//     a=b;
//     b=tmp;
// }

// int main(){
//     int a=10;
//     int b=20;
//     int c=30;
//     const int &d=a+b;
//     swap(a,c);
// }


// class A{
// private:
//     int a;
// public:
//     void print(){
//         cout << "Print()" << endl;
//     }
//     void printA(){
//         cout << a << endl;
//     }
// };


int main()
{
    // A* p = nullptr;//空this指针，调用成员函数编译会通过，但其结果未定义，程序可能崩溃或正常运行。
    // p->print();
    // p->printA();
    //Date a(2020,11,1);
    //a.Print();
    //Date b(2019,12,1);
    //Date d(2020,11,2);
    // b.Print();
    // cout<<(a>b)<<endl;
    // cout<<(a<b)<<endl;
    // cout<<(a<d)<<endl;
    //Date c(a);
    //c.Print();
    // cout<<(a==c)<<endl;
    // cout<<(a!=b)<<endl;

    // int day=10;
    // (a+=day).Print();
    // (a-=day).Print();
    // (++a).Print();
    // (--a).Print();
    // (a++).Print();
    // a.Print();
    // (a--).Print();
    // a.Print();

    // Date a(2020,1,20);
    // Date b(2020,12,1);
    // cout << a;
    // cout << b;
    // cout<<a.UpToNow()<<endl;
    // cout<<b.UpToNow()<<endl;

    // //cout<<abs(a.UpToNow()-b.UpToNow())<<endl;

    // cout<<(a-b)<<endl;
    // cout<<"Done!";
    int num = 0;
    int* p=&num;
    cout<<p<<" "<<sizeof(p);


    return 0;
}