#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using std::string;

const int ALL = 0x1f1f1f;

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