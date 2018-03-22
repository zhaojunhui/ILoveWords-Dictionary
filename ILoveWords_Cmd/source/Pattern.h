#ifndef PATTERN_H
#define PATTERN_H

#include "Processor.h"

using std::string;

class Pattern
{
	friend class Processor;
public:
	
	//任务开始
	virtual void Start() = 0;
	
	//任务结束（可能进行一些收尾工作）
	virtual void Quit() = 0;
	
	//响应命令
	virtual void RunCmd (const string& cmd) = 0;

	void SetDictname_(const string& dict)
	{
		dictname_ = dict;
	}

	void SetUsername_(const string& user)
	{
		username_ = user;
	}

	//构造函数
	Pattern (const string& user, const string& dict, Processor* proc);

protected:
	Processor* processor_;
	string dictname_;
	string username_;
};



#endif //PATTERN_H
