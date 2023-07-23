#include <QCoreApplication>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;


#if 0
// ---------------------------- 仿函数 start -----------------------------
/**
函数对象：
    重载函数调用操作符(), 对象称为函数对象
    1,  本质是一个类， 不是对象；
    2,  具有普通函数的特点，
    3， 函数对象可以有自己的对象，
    4， 函数对象可以作为参数传递；
*/
class MyAdd
{
public:
    int operator()(int v1, int v2)
    {
        return v1+ v2;
    }
};
class myPrint
{
public:
    myPrint() :count(0)
    {

    }
    void operator()(const string& str)
    {
        cout << str << endl;
        count++;
    }
    int count;
};

void doPrint(myPrint& p, string str)
{
    p(str);
}
void test01(void)
{
    MyAdd add;
    cout << "10+20: " << add(10, 20) << endl;

    myPrint p;
    p("hello world");
    p("hello world");
    p("hello world");
    p("hello world");
    p("hello world");

    cout << "p count: " << p.count << endl;

    doPrint(p, "Hello C++");
}

class GreatorFive
{
public:
    bool operator()(int val)
    {
        return val > 5;
    }
};
void test02()
{
    // 一元谓词：
    // 重载()的仿函数的返回值为bool类型，并且参数列表中只有一个参数，这样的仿函数称为一元谓词，类似的还有二元谓词；
    // 在vector列表中查找第一个大于5的元素
    vector<int> v;
    for(int i = 0;i < 10;i++)
    {
        v.push_back(i);
    }

    vector<int>::iterator it = find_if(v.begin(), v.end(), GreatorFive());
    if(it!=v.end())
    {
        cout << "find GreaterFive pos: " << *it << endl;
    }
    else
    {
        cout << "Not Find GreatorFive " << endl;
    }
}

int main(void)
{
//    test01();
    test02();

    cout << "hello funtion object." << endl;
    return 0;
}
// ---------------------------- 仿函数 end -----------------------------
#endif



