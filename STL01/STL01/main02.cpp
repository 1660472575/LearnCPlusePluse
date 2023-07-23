#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <list>
#include <set>
#include <map>

/**
Vector, list, string, set, map
*/


using namespace std;

/******************* map begin *************************/
#if 0
// 成对出现： <key, val>, key:索引
// 高效率，高性能
// 按照key值进行排序， key不允许重复

void printMap(const map<int, string>& m)
{
    for(map<int, string>::const_iterator it=m.begin();it!=m.end();it++)
    {
        cout << "val: " << it->first << " key: " << it->second << endl;
    }
    cout << endl;
}

void test01(void)
{
    map<int, string> m;
    m.insert(pair<int, string>(10, "A1"));
    m.insert(pair<int, string>(14, "A2"));
    m.insert(pair<int, string>(12, "A3"));
    m.insert(pair<int, string>(11, "A4"));
    m.insert(pair<int, string>(19, "A5"));
    m.insert(make_pair(20, "A6"));

    printMap(m);

    // empty(), size(), swap()

    // insert(), clear(), erase()注意重载

    // find(), count()统计key元素的格式

    // sort()
}

class MyCompare
{
public:
    bool operator()(int a1, int a2) const
    {
        return a1>a2;
    }
};
void test02()
{
    map<int, string, MyCompare> m;
    m.insert(pair<int, string>(10, "A1"));
    m.insert(pair<int, string>(14, "A2"));
    m.insert(pair<int, string>(12, "A3"));
    m.insert(pair<int, string>(11, "A4"));
    m.insert(pair<int, string>(19, "A5"));
    m.insert(make_pair(20, "A6"));

//    printMap(m);
    for(map<int, string, MyCompare>::iterator it=m.begin();it!=m.end();it++)
    {
        cout << "key: " << it->first << " val: " << it->second << endl;
    }
}


int main(void)
{
//    test01();
    test02();

    cout << "hello map." << endl;
    return 0;
}

#endif
/******************* map end *************************/


/******************* set begin *************************/
#if 0
void printSet(const set<int> &s)
{
    for(set<int>::const_iterator it=s.begin();it!=s.end();it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// set 不允许有重复的元素，插入元素时进行排序；
void test01()
{
    set<int> s;
    for(int i=0;i<10;i++)
    {
        s.insert(i);
    }
    s.insert(90);
    s.insert(56);
    printSet(s);
    set<int> s2(s);
    printSet(s2);
    set<int> s3;
    s3 = s;

    // size(), empty(), swap()
    cout << "s2.empty(): " << s2.empty() << endl;
    cout << "s2.size(): " << s2.size() << endl;
    set<int> s4;
    s4.swap(s2);
    printSet(s4);
    cout << "print s2: " << endl;
    printSet(s2);

    // insert(), clear(), erase()

    // find(), count()
    set<int>::iterator it = s3.find(9);
    if(it != s3.end())
    {
        cout << "find val: " << *it << endl;
    }

    cout << "count 8: " << s3.count(8) << endl;
}
void printMSet(const multiset<int>& ms)
{
    for(multiset<int>::iterator it= ms.begin();it!=ms.end();it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
void test02()
{
    multiset<int> ms;
    ms.insert(10);
    ms.insert(10);
    ms.insert(20);
    ms.insert(11);
    ms.insert(11);
    printMSet(ms);
}
void test03()
{
    // 对组
    pair<string, int> p1("Tom", 21);
    cout << "name: " << p1.first << " age: " << p1.second << endl;
    pair<string, int> p2 = make_pair("Jary", 22);
}
class MyCompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1>v2;
    }
};
void test04()
{
    // 修改set容器的sort()规则
    set<int> s;
    s.insert(22);
    s.insert(12);
    s.insert(11);
    s.insert(92);
    s.insert(60);
    s.insert(30);
    s.insert(20);
    printSet(s);

    set<int, MyCompare> s1;
    s1.insert(22);
    s1.insert(12);
    s1.insert(11);
    s1.insert(92);
    s1.insert(60);
    s1.insert(30);
    s1.insert(20);
    for(set<int, MyCompare>::iterator it=s1.begin();it!=s1.end();it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
class Person
{
public:
    Person(string name, int age)
    {
        this->m_name = name;
        this->m_age = age;
    }
    string m_name;
    int m_age;
};
class PersonCompare
{
public:
    bool operator()(const Person& p1, const Person& p2)
    {
        return p1.m_age < p2.m_age;
    }
};
void test05()
{
    // 自定数据类型指定sort()规则
    set<Person, PersonCompare> s;
    Person p1("A1", 22);
    Person p2("A2", 12);
    Person p3("A3", 11);
    Person p4("A4", 92);
    Person p5("A5", 60);
    Person p7("A7", 30);
    Person p6("A6", 20);

    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);
    s.insert(p5);
    s.insert(p7);
    s.insert(p6);

    for(set<Person>::iterator it=s.begin();it!=s.end();it++)
    {
        cout << "name: " << it->m_name << " age: " << it->m_age << endl;
    }
}

int main(void)
{
//    test01();
//    test02();
//    test03();
//    test04();
    test05();

    cout << "hello queue." << endl;
    return 0;
}
#endif
/******************* set end *************************/


/******************* list begin *************************/
// list插入和删除数据，迭代器不会失效，vector是不具备的
#if 0
// 构造函数
// list<T> lst, list(begin, end), list(n, elem), list(const list& lst);

// 赋值交换
// assign()， =操作, swap()
// size(), empty(), resize()
// push_back(), pop_back()
// push_front(), pop_front()
// insert() 多个重载版本
// clear()
// erase() 重载
// remove()

// front(), back()

// reverse(), sort()这个是成员函数

/**
将Person自定义数据类型进行排序，包括姓名、年龄、身高；
排序规则： 按照年龄排序，如果年龄相同按照升高降序；
*/

class Person
{
public:
    Person(string name, int age, int height)
    {
        this->m_name = name;
        this->m_age = age;
        this->m_height = height;
    }
    string m_name;
    int m_age;
    int m_height;
};
void printList(const list<Person> &l)
{
    for(list<Person>::const_iterator it=l.begin();it!=l.end();it++)
    {
        cout << "name: "<< it->m_name << " age: " << it->m_age << " heigth: " << it->m_height << endl;
    }
    cout << endl;
}
// 自定义排序规则
bool comparePerson(Person& p1, Person& p2)
{
    if(p1.m_age == p2.m_age)
    {
        return p1.m_height > p2.m_height;
    }
    else
    {
        return p1.m_age < p2.m_age;
    }
}
void test01()
{
    list<Person> lst;
    Person p1("A1", 35, 175);
    Person p2("A2", 45, 100);
    Person p3("A3", 40, 170);
    Person p4("A4", 25, 190);
    Person p5("A5", 35, 160);
    Person p6("A6", 35, 200);
    Person p7("A7", 22, 170);

    lst.push_back(p1);
    lst.push_back(p2);
    lst.push_back(p3);
    lst.push_back(p4);
    lst.push_back(p5);
    lst.push_back(p6);
    lst.push_back(p7);

    printList(lst);
    cout << "---------------- after sort -----------------" << endl;
    lst.sort(comparePerson);
    printList(lst);
}

int main(void)
{
    test01();

    cout << "hello queue." << endl;
    return 0;
}
#endif
/******************* list end *************************/


/******************* queue begin *************************/
// 队列容器允许一端新增数据，另一端移除数据。
// 只能访问两端数据， 先进先出
// 不允许遍历数据
// push() pop() front() back()
// size() empty()
#if 0
void test01()
{
    queue<int> q;
    for(int i =0;i< 10;i++)
    {
        q.push(i+1);
    }
    cout << "q.size: " << q.size() << endl;
    cout << "q.back: " << q.back() << endl;
    cout << "q.front: " << q.front() << endl;

    while(!q.empty())
    {
        cout << q.front() <<" ";
        q.pop();
    }
    cout << endl;
    cout << "q.size: " << q.size() << endl;
    cout << "q.back: " << q.back() << endl;
    cout << "q.front: " << q.front() << endl;
}


int main(void)
{
    test01();

    cout << "hello queue." << endl;
    return 0;
}
#endif
/******************* queue end *************************/



/******************* stack begin *************************/
// 先进后出
// 不允许遍历数据
#if 0
// push() pop() top()
// empty() size()
void test01()
{
    stack<int> s;
    for(int i=0;i< 10;i++)
    {
        s.push(i);
    }
    cout << "stack top: " << s.top() << endl;
    cout << "stack size: " << s.size() << endl;
    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    cout << "stack size: " << s.size() << endl;
}

int main(void)
{
    test01();

    cout << "hello stack." << endl;
    return 0;
}
#endif
/******************* stack begin *************************/
