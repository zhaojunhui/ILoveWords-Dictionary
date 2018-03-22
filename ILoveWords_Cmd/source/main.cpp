#include <iostream>
#include "Shell.h"
#include "DataBase.h"
#include "Processor.h"
using namespace std;

int main()
{
	string ans;
	Shell cur_shell;
	string tmp;
	getline(cin,tmp);
	cur_shell.LoadCmd();
	return 0;
}
