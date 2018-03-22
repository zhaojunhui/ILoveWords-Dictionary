#include "Pattern.h"
#include <iostream>
using namespace std;

Pattern::Pattern (const string& user, const string& dict, Processor* proc) : processor_(proc)
{
	username_ = user;
	dictname_ = dict;
}
