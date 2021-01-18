/**
 * 输入一个不多于4位的正整数，要求按逆序打印出各个位上的数字，例如原数为23，应输出32；如原数为8000，应输出0008；
 * 如原数为1，则输出1。应测试以下情况：输入的数为1位、2位、3位、4位正整数；此外，还应测试以下异常情况：输入负数或0，或输入的数超过4位。
 * 输入说明 :

 * 输入一个整数，可能为0，也可能为负数。
 * 输出说明 :

 * 输入1到4位的正整数时，输出该数的逆序，如果是其它整数，则输出“error!”。输出时，行首与行尾均无空格。
 * 输入范例 :

 * 8000
 * 输出范例 :

 * 0008
*/
#include <iostream>
#include <string.h>
#include <sstream>
using namespace std;

/**
 * @param x 需要逆序的数
*/
void reverse(int x)
{
    string xs = to_string(x);
    stringstream st; // 字符串流
    if (xs.length() > 4 || x < 0)
        cout << "error!";
    else
    {
        // 逆序
        for (int i = xs.size() - 1; i >= 0; --i)
        {
            st << xs[i]; // 放入流中
        }
        cout << st.str();
    }
}
int main(void)
{
    int x = 0;
    cout << "请输入一个不多于4位的整数" << endl;
    cin >> x;
    reverse(x);
}
