#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

/******************* text begin *************************/
#if 0
// 评委打分：10个评委分别给5个选手打分，去掉最高分和最低分，最后获得平均分；
// 练习：string, vector, deque
class Person
{
public:
    Person(string name, int score)
    {
        this->m_name = name;
        this->m_score = score;
    }
    string m_name;
    int m_score;
};
void createPerson(vector<Person> &v)
{
    string nameList = "ABCDE";
    for(int i = 0;i < 5;i++)
    {
        string name = string("Person") + nameList[i];
        int score = 0;
        v.push_back(Person(name, score));
    }
}
void setScore(vector<Person> &v)
{
    for(vector<Person>::iterator it = v.begin();it!=v.end();it++)
    {
        deque<int> ds;
        int av_score = 0;
        for(int i = 0;i < 10;i++)
        {
            av_score = rand() % 41 + 60;
            ds.push_back(av_score);
        }
        sort(ds.begin(), ds.end());
        ds.pop_back();
        ds.pop_front();
        av_score = 0;
        for(int i =0;i < (int)ds.size();i++)
        {
            av_score += ds.at(i);
        }
        av_score /= ds.size();
        it->m_score = av_score;
    }
}
void showScore(const vector<Person> &v)
{
    for(vector<Person>::const_iterator it=v.begin();it!=v.end();it++)
    {
        cout << "Name: " << it->m_name << " av_score: " << it->m_score << endl;
    }
}
void test()
{
    vector<Person> v;
    // 1，创建五个选手
    createPerson(v);
    // 2. 给五个选手打分
    setScore(v);
    //3. 展示最终分数
    showScore(v);
}

int main(void)
{
    // 添加随机数种子
    srand((unsigned int)(time(NULL)));
    test();
    cout << "hello deque " << endl;
    return 0;
}
#endif
/******************* text end *************************/

/******************* deque begin *************************/
#if 0
void printDeque(const deque<int>& d)
{
    for(deque<int>::const_iterator it = d.begin();it != d.end();it++)
    {
        cout << *it <<  " ";
    }
    cout << endl;
}
// deque类似双端数组
void test01()
{
    // deque构造函数
    deque<int> d;
    for(int i=0;i<10;i++)
    {
        d.push_back(i);
    }
    printDeque(d);
    /*
    deque赋值操作：
    */
    deque<int> d1;
    d1 = d;
    cout << "print d1: " << endl;
    printDeque(d1);
    deque<int> d2;
    d2.assign(d1.begin(), d1.end());
    deque<int> d3(10, 100);
    printDeque(d3);
    // 大小操作：
//    d1.empty();
//    d1.size();
//    d1.resize();
}

void test02()
{
    // deque容器的插入和删除操作：
    deque<int> d;
    for(int i=0;i< 10;i++)
    {
        d.push_front(i);
    }
    printDeque(d);
    // 下面注意函数重载
    // 两端操作：
//    d.push_back()
//    d.push_front()
//    d.pop_back()
//    d.pop_front()
    // 指定位置操作：
//    d.insert()
//    d.clear()
//    d.erase()
}
void test03()
{
    // deque容器数据存取操作：
    // at()
    // [] 类似数组操作
    // front() , back()
    deque<int> d;
    for(int i=0;i<10;i++)
    {
        d.push_back(i);
    }
    printDeque(d);
    cout << "d[2]: " << d[2] << endl;
    cout << "d.at(2): " << d.at(2) << endl;
    cout <<"d.front(): " << d.front() << endl;
    cout << "d.back(): " << d.back() << endl;
    // deque容器排序 sort()
    // vector也支持sort()排序
    d.at(2) = 20;
    d[6] = 13;
    cout << "random insert val: " <<endl;
    printDeque(d);
    cout << "after sort: " << endl;
    sort(d.begin(), d.end());
    printDeque(d);
}

int main(void)
{
//    test01();
//    test02();
    test03();
    cout << "hello deque " << endl;
    return 0;
}
#endif
/******************* deque end *************************/

/******************* vector begin *************************/

#if 0
// vector 单端数组
void printVector(vector<int> &v)
{
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
void test01()
{
    vector<int> v;
    for(int i = 0;i < 10;i++)
    {
        v.push_back(i);
    }
    printVector(v);
    // 使用等号 = 赋值
    // 使用assign()赋值
}
void test02()
{
    // 容量、大小的操作
    vector<int> v;
    for(int i = 0;i < 10;i++)
    {
        v.push_back(i);
    }
    printVector(v);
    // 1. 容量
//    v.empty();
//    v.capacity();
    cout << "v.empty: " << v.empty() << endl;
    cout << "v.capacity: " << v.capacity() << endl;

    // 2. 大小
//    v.size();
//    v.resize();
    cout << "v.size(): " << v.size() << endl;
    v.resize(14);
    printVector(v);
    cout << "v.resize(14): " << v.size() << endl;
}
void test03()
{
    /**
插入和删除：
    push_back()
    pop_back()
    insert()
    erase()
    clear()
    */
    vector<int> v;
    for(int i = 0;i < 10;i++)
    {
        v.push_back(i);
    }
    printVector(v);
    v.insert(v.begin(), 23);
    cout << "insert 23: " << endl;
    printVector(v);

    cout << "erase ++v.begin() :" << endl;
    v.erase(++v.begin());
    printVector(v);

    cout << "v.pop_back(): " << endl;
    v.pop_back();
    printVector(v);

    cout << "v.clear() : " << endl;
    v.clear();
    printVector(v);
}
void test04()
{
    /**
数据存取：
    at()
    []
    front()
    back()
    */
    vector<int> v;
    for(int i = 0;i < 10;i++)
    {
        v.push_back(i);
    }
    printVector(v);
    cout << "v.at(0): " << v.at(0) << endl;
    cout << "v[1]: " << v[1] << endl;
    cout << "v.front(): " << v.front() << endl;
    cout << "v.back(): " << v.back() << endl;
}
void test05()
{
    /*
Vector 容器元素互换：
    swap()
*/
    vector<int> v1;
    vector<int> v2;
    for(int i = 0;i < 5;i++)
    {
        v1.push_back(i);
        v2.push_back(i+2);
    }
    cout << "print V1: ";
    printVector(v1);

    v2.push_back(78);
    cout << "\n print v2: ";
    printVector(v2);
    cout << "swap v1 and v2: " << endl;
    v1.swap(v2);
    printVector(v1);
    printVector(v2);

    // 具有收缩内存的作用
    // 匿名对象：当前行运行结束，释放内存
    vector<int>(v1).swap(v1);
}
void test06()
{
    // reserve() 预留内存空间， 减少自动扩展内存的次数
    vector<int> v;
    int cnt = 0;
    int* p = NULL;
    v.reserve(100000); //  减少重新分配内存为1次， 否则为18.
    for(int i = 0;i < 100000;i++)
    {
        v.push_back(i);
        if(p != &v[0])
        {
            p = &v[0];
            cnt++;
        }
    }
    cout << "re-mem cnt: " << cnt << endl;
}
int main(void)
{
//    test01();
//    test02();
//    test03();
//    test04();
//    test05();
    test06();
    cout << "hello stl" << endl;
    return 0;
}
#endif
/******************* vector end *************************/

/******************* String begin *************************/

#if 0
// String构造函数：
/**
string()
string
*/
void test01()
{
    //1. string拼接
    string s1 = "hello world";
    string s2;
    s2 += s1 + " here";
    s2.append(" 123");
    cout << "s2: " << s2 << endl;

    // 2. string 查找find
    string a1 = "hello world";
    int pos = a1.find("aa");  // 没有找到返回-1
    cout << "find pos: " << pos << endl;
    if(pos != -1)
    {
        cout << "find substr " << endl;
    }
    else {
        cout << "not find aa" << endl;
    }

    // 3. string 替换replace
    a1.replace(0, 5, "this is");
    cout << "replace after: " << a1 << endl;

    // 4. 比较compare
    // 5. 存储
    string a2 = "hello123";
    a2.at(1);
    a2[3];
    a2.size();

    // 6. string insert, erase
    // 7. 截取子串substr()
    cout << " substr: " << a2.substr(1, 3) << endl;

}
int main(void)
{
    test01();
    cout << "hello stl" << endl;
    return 0;
}
#endif
/******************* String end *************************/

/******************* Vector begin *************************/
#if 0
// vector存储自定义数据：
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

void test01()
{
    vector<Person> v1;

    Person p1("A1", 10);
    Person p2("A2", 20);
    Person p3("A3", 30);
    Person p4("A4", 40);
    Person p5("A5", 50);

    v1.push_back(p1);
    v1.push_back(p2);
    v1.push_back(p3);
    v1.push_back(p4);
    v1.push_back(p5);
    cout << "start print v1:" << endl;
    for(vector<Person>::iterator it = v1.begin();it != v1.end();it++)
    {
        cout << "name: " << it->m_name << " age: " << it->m_age << endl;
    }

    vector<Person*> v2;
    Person s1("B1", 10);
    Person s2("B2", 20);
    Person s3("B3", 30);
    Person s4("B4", 40);
    Person s5("B5", 50);

    v2.push_back(&s1);
    v2.push_back(&s2);
    v2.push_back(&s3);
    v2.push_back(&s4);
    v2.push_back(&s5);
    cout << "start print v2: " << endl;
    for(vector<Person*>::iterator it = v2.begin(); it != v2.end();it++)
    {
        cout << "Name: " << (*it)->m_name << " Age: " << (*it)->m_age << endl;
    }
}
// vector嵌套
void test02()
{
    vector<vector<int>> v;
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;
    vector<int> v5;

    for(int i = 0;i < 5;i++)
    {
        v1.push_back(i + 1);
        v2.push_back(i + 2);
        v3.push_back(i + 3);
        v4.push_back(i + 4);
        v5.push_back(i + 5);
    }

    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    v.push_back(v5);

    cout << "start print V: " << endl;
    for(vector<vector<int>>::iterator it = v.begin();it != v.end();it++)
    {
        for(vector<int>::iterator vit = it->begin(); vit != it->end(); vit++)
        {
            cout << *vit << " ";
        }
        cout << endl;
    }
}

int main(void)
{
//    test01();
    test02();
    cout << "hello stl" << endl;
    return 0;
}
#endif

#if 0
// Vector类似数组初识
void printVector(int &val)
{
    cout << val << endl;
}
void test01()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    // 遍历vector
    // 1. while循环遍历
    vector<int>::iterator itbegin = v.begin();
    vector<int>::iterator itend = v.end();
    cout << "while print vector...." << endl;
    while(itbegin != itend)
    {
        cout << *itbegin << endl;
        itbegin++;
    }
    cout << endl;
    cout << "for print vector...." << endl;
    //2. for()
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it  << endl;
    }
    cout << endl;
    cout << "for_each print vector...." << endl;
    for_each(v.begin(), v.end(), printVector);
}


int main(void)
{
    test01();
    cout << "hello stl" << endl;
    return 0;
}
#endif
/******************* Vector end *************************/
