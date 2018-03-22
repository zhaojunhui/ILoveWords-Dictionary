#include "Pattern.h"
#include <iostream>
#include <string>

using std::string;

class MainPattern : public Pattern
{
public:
	using Pattern::Pattern;
	void Start();
	void RunCmd(const string& cmd);
	void Quit() {}
private:
	bool Judge(const string& cmd);
};

