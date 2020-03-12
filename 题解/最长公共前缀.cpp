#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    string prefix = strs.at(0).substr(0, 1);
    for (int i = 1; i < strs.size(); i++)
    {
        int j = 1;
        while(prefix == strs.at(i).substr(0,j)){
            prefix = strs.at(i).substr(0,j++);
        }
        
    }
}
int main()
{
}