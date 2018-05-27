#include<iostream>
using namespace std;
class Person
{
public:
    Person()
    {
        cout << "contructor"<< endl;
    }
    ~Person()
    {
        cout << "destructor"<< endl;
    }

};
int divide(int x,int y)
{
    Person p1,p2;
    if(y==0)
    {
        throw y;
    }
    return x/y;
}
void test01()
{
    try{
        divide(10,0);
    }catch(int e){
        cout << "catch something!"<< endl;
    }
}
int main()
{
    test01();
    return 0;
}
