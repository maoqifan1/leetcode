/**
 * 根据一个范围在0至6的整数，用英文输出它对应的是星期几。（0对应Sunday，1对应Monday， 2对应Tuesday， 3对应Wednesday， 4对应Thursday， 5对应Friday， 6对应Saturday）

输入说明 :

输入一个整数n（0 ≤ n ≤ 6）。在行首和行尾没有多余的空格。

输出说明 :

输出一个字符串，即输入n对应的星期几的英文名称，请注意大小写。在行首和行尾不要输出多余的空格。


*/
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string str;
    switch (n)
    {
    case 0:
        str = "Sunday";
        break;
    case 1:
        str = "Monday";
        break;
    case 2:
        str = "Tuesday";
        break;
    case 3:
        str = "Wednesday";
        break;
    case 4:
        str = "Thursday";
        break;
    case 5:
        str = "Friday";
        break;
    case 6:
        str = "Saturday";
        break;
    default:
        break;
    }
    cout << str;
}