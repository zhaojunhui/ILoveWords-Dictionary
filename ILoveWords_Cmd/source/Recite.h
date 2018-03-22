#ifndef RECITE_H
#define RECITE_H

#include <string>
#include "Word.h"
#include "Pattern.h"

class Processor; class DataBase;

class Recite : public Pattern
{
public:
	bool Init();
	void Step0();
	void StepYes();
	void StepNo();
	void Next();
	void Undo();
	void SetWordPerDay(const string &);//次日生效
	
	void Start();
	void Quit() {}
	void RunCmd (const std::string& cmd);
	
	SingleWord cur_word_;
	struct tm *cur_time_;
	int period_;
	int word_period_;

	bool legal_next_;
	bool legal_undo_;
	bool legal_YN_;
	
	
public:
	Recite (const std::string& username, const std::string& dictname, Processor* proc);
	
};


#endif