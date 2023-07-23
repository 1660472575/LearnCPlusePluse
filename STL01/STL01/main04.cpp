#include <QCoreApplication>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;


/******************************* 集合 begin ***********************************/
#if 1
///// 容器必须是有序的集合
// set_intersection: 集合的交集
// set_union: 并集
// set_difference: 差集
void print01(const int& val)
{
    cout << val << " ";
}

void test01()
{
    vector<int> v1;
    vector<int> v2;
    for(int i=0;i<10;i++)
    {
        v1.push_back(i);
        v2.push_back(i+6);
    }
    cout << "print vector 1: " << endl;
    for_each(v1.begin(), v1.end(), print01);

    cout << "\n print vector 1: " << endl;
    for_each(v2.begin(), v2.end(), print01);

    // 求两个容器的交集
    cout << "\n make vector intersection: " << endl;
    vector<int> v_inter;
    v_inter.resize(v1.size());
    vector<int>::iterator itend = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v_inter.begin());
    for_each(v_inter.begin(), itend, print01);

    // 求两个容器的并集
    cout << "\n make vector union:" << endl;
    vector<int> v_union;
    v_union.resize(v1.size()+v2.size());
    itend = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v_union.begin());
    for_each(v_union.begin(), itend, print01);

    // 求两个容器的差集
    cout << "\n make vector difference:" << endl;
    vector<int> v_diff;
    v_diff.resize(max(v1.size(), v2.size()));
    itend = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v_diff.begin());  // 差集
    for_each(v_diff.begin(), itend, print01);
}

int main(void)
{
    test01();
//    test02();
//    test03();

    cout << "\n hello functional." << endl;
    return 0;
}
#endif
/******************************* 集合 end ***********************************/

/******************************* 算术生成算法 begin ***********************************/
// accumulate: 计算容器元素累加和
// fill: 向容器中添加元素
/******************************* 算术生成算法 end ***********************************/


/******************************* copy、 替换算法 begin ***********************************/
// copy
// replace:
// replace_if:
// swap:


/******************************* copy、 替换算法 end ***********************************/

/******************************* 排序算法 begin ***********************************/
#if 0
// sort:
// random_shuffle():
// merge:
// reverse:



int main(void)
{
//    test01();
//    test02();
//    test03();

    cout << "\n hello functional." << endl;
    return 0;
}
#endif
/******************************* 排序算法 end ***********************************/



/******************************* 查找算法 begin ***********************************/
#if 0
// 查找算法：
// find:
// find_if()
// adjacent_find: 查找相邻的重复元素
// binary_search:
// count: 统计个数
// count_if: 按条件统计个数


// 查找内置的数据类型
void test01()
{
    vector<int> v1;
    for(int i=0;i<50;i++)
    {
        v1.push_back(i);
    }
    // find(5)
    vector<int>::iterator it = find(v1.begin(), v1.end(), 90);
    if(it != v1.end())
    {
        cout << "find data: " << *it << endl;
    }
    else
    {
        cout << "not find data: 5." << endl;
    }
}

class Person
{
public:
    Person(string name, int age)
    {
        this->m_name = name;
        this->m_age = age;
    }
    // 重载==
    bool operator==(const Person& p)
    {
        return ((this->m_age == p.m_age) && (this->m_name == p.m_name));
    }
    string m_name;
    int m_age;
};

// 查找自定义数据
void test02()
{
    Person p1("A1", 10);
    Person p2("A2", 60);
    Person p3("A3", 30);
    Person p4("A4", 40);
    Person p5("A5", 80);
    Person p6("A6", 20);

    vector<Person> v;
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    v.push_back(p6);

    // 查找指定元素需要重载==
    vector<Person>::iterator it = find(v.begin(), v.end(), p4);
    if(it != v.end())
    {
        cout << "find person name: " << it->m_name << " age: " << it->m_age << endl;
    }
    else
    {
        cout << "NOT find person name: " << it->m_name << " age: " << it->m_age << endl;
    }
}

class GreaterFive
{
public:
    bool operator()(const int& val)
    {
       return (val > 5);
    }
};
class OldMain
{
public:
    bool operator()(const Person& p)
    {
        return (p.m_age > 60);
    }
};

// find_if()
void test03()
{
    // 查找内置数据类型
    vector<int> v1;
    for(int i=0;i<100;i++)
    {
        v1.push_back(i);
    }

    vector<int>::iterator it = find_if(v1.begin(), v1.end(), GreaterFive()); // 指定谓词
    if(it!=v1.end())
    {
        cout << "find grater 5: " << *it << endl;
    }

    // 查找自定义数据类型
    Person p1("A1", 10);
    Person p2("A2", 60);
    Person p3("A3", 30);
    Person p4("A4", 40);
    Person p5("A5", 80);
    Person p6("A6", 20);

    vector<Person> v2;
    v2.push_back(p1);
    v2.push_back(p2);
    v2.push_back(p3);
    v2.push_back(p4);
    v2.push_back(p5);
    v2.push_back(p6);

    // 查找年龄大于60的人
    vector<Person>::iterator pit = find_if(v2.begin(), v2.end(), OldMain());
    if(pit != v2.end())
    {
        cout << "find name: " << pit->m_name << " age: " << pit->m_age << endl;
    }
    else
    {
        cout << "find name: " << pit->m_name << " age: " << pit->m_age << endl;
    }
}
void test04()
{

}


int main(void)
{
//    test01();
//    test02();
    test03();

    cout << "\n hello functional." << endl;
    return 0;
}
#endif
/******************************* 查找算法 end ***********************************/


/******************************* 常用遍历算法 begin ***********************************/
#if 0
// for_each(): 遍历元素
// transform(): 把容器中的元素搬运到另一个容器

void print01(const int& val)
{
    cout << val << " ";
}
class print02
{
public:
    void operator()(const int& val)
    {
        cout << val << " ";
    }
};
class mTransform
{
public:
    int operator()(const int& val)
    {
        return val;
    }
};

void test01()
{
    // for_each
    vector<int> v1;
    for(int i=0;i<10;i++)
    {
        v1.push_back(i);
    }
    cout << "common function: " << endl;
    for_each(v1.begin(),v1.end(), print01); // 仿函数或者普通函数
    cout << endl;
    cout << " 使用仿函数： "<< endl;
    for_each(v1.begin(), v1.end(), print02());
    cout << endl;
}
void test02()
{
    // transform()
    vector<int> src;
    for(int i=0;i<10;i++)
    {
        src.push_back(i);
    }
    vector<int> dst;
    dst.resize(src.size());
    transform(src.begin(), src.end(), dst.begin(), mTransform()); // mTransform() 搬数据时运算后放到容器中
    for_each(dst.begin(), dst.end(), print02());
}

int main(void)
{
//    test01();
    test02();

    cout << "\n hello functional." << endl;
    return 0;
}
#endif
/******************************* 常用遍历算法 end ***********************************/



/******************************* 内建函数对象 begin ***********************************/
#if 0
// 内建函数对象 #include <functional>
// 算术、关系、逻辑仿函数
// 算术仿函数：实现四则运算: plus、minus、multiplies、divides、modules、negate
// 关系仿函数：关系对比： equal_to、not_equal_to、greater、greater_eqaul、less、less_equal
// 逻辑仿函数：实现逻辑运算： logical_and、 logical_or、 logical_not

void test01()
{
    // 算术仿函数
    // 取反
    negate<int> n;
    cout << "nagate: " << n(20) << endl;
    // 相加
    plus<int> p;
    cout << "10+20: " << p(10, 20) << endl;

    // 关系仿函数
    // 大于
    vector<int> v1;
    v1.push_back(20);
    v1.push_back(10);
    v1.push_back(50);
    v1.push_back(30);
    v1.push_back(60);
    for(vector<int>::iterator it = v1.begin();it!=v1.end();it++)
    {
        cout << *it <<  " ";
    }
    cout << endl;

    //  使用关系仿函数进行排序 // 或者自定义使用谓词
    sort(v1.begin(), v1.end(), greater<int>());

    for(vector<int>::iterator it = v1.begin();it!=v1.end();it++)
    {
        cout << *it <<  " ";
    }
    cout << endl;

    // 使用逻辑仿函数，
    vector<bool> v2;
    v2.push_back(false);
    v2.push_back(true);
    v2.push_back(false);
    v2.push_back(true);
    v2.push_back(false);
    v2.push_back(true);

    for(vector<bool>::iterator it=v2.begin();it!=v2.end();it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    vector<bool> v3;
    v3.resize(v2.size());
    // 在 搬运容器中数据时， 对数据进行取反操作
    transform(v2.begin(),v2.end(),v3.begin(),logical_not<bool>());
    for(vector<bool>::iterator it=v3.begin();it!=v3.end();it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main(void)
{
    test01();
//    test02();

    cout << "hello functional." << endl;
    return 0;
}
#endif
/******************************* 内建函数对象 end ***********************************/
