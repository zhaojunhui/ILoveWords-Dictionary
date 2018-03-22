#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using std::string;

const int ALL = 0x1f1f1f;


/*前后去空格，不区分大小写*/
inline void ToStdForm (string& s)
{
    if (s == "") return;
    string::size_type beg = s.find_first_not_of(' ');
    string::size_type end = s.find_last_not_of(' ');
    s = s.substr(beg, end - beg + 1);
    for (int i = 0; i < s.length(); i++) s[i] = tolower(s[i]);
}

/*整数化成string*/
inline string IntToString (int n)
{
    if (n == 0) return "0";
    string s;
    if (n < 0) n = -n;
    while (n > 0)
    {
        s += (char)((n % 10) + '0');
        n /= 10;
    }
    std::reverse (s.begin(), s.end());
    if (n < 0) s = '-' + s;
    return s;
}

/*字符串化成整数*/
inline int StringToInt (const string& s)
{
    int n = s.length();
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        if (isdigit (s[i]))
            ret *= 10, ret += (int)(s[i] - '0');
        else
            return -1;
    }
    return ret;
}

/*分析所有形如 base i 的指令，返回i */
inline int DecodeCmd (const string& cmd, const string& base, int range)
{
    for (int i = 1; i <= range; i++)
        if (cmd == base + ' ' + IntToString (i) || cmd == base + IntToString (i))
            return i;
    if (cmd == base + " *" || cmd == base + "*")
        return ALL;
    return 0;
}


#endif //FUNC_H
