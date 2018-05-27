#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    int val = 42;
    auto result = find(vec.cbegin(),vec.cend(),val);
    cout << "the value"<<val
        <<(result == vec.cend()
           ? "is not present":"is present")<<endl;
    return 0;
}
