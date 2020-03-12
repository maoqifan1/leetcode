#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Solution
{
public:
    inline int gcd(int a, int b) // 辗转相除求最大公因数
    {
        return b == 0 ? a : gcd(b, a % b);
    }
    string gcdOfStrings(string str1, string str2)
    {
        if (str1 + str2 != str2 + str1)
            return "";
        return str1.substr(0, gcd(str1.size(), str2.size()));
    }
};
int main(void)
{
    Solution *c = new Solution();
    string res = c->gcdOfStrings("ababababab", "abcsdabd");
    cout << "字符串的最大公因子是: " << res << endl;
    delete c;
}