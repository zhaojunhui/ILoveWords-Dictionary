#ifndef QUERY_H
#define QUERY_H


#include <iostream>
#include <string>
#include "Pattern.h"
#include "Word.h"

class Processor;
class Log; class DataBase;

class Query : public Pattern
{
public:
	Query (const string& username, const string& dictname, Processor* proc);
	~Query();
	
public:
	virtual void Start();
	virtual void Quit();
	virtual void RunCmd (const std::string& cmd);
	DataBase* GetDataBase() const;

private:
	inline int isDelCmd (const std::string& cmd) const;
	inline int isSetCmd (const std::string& cmd) const;
	inline bool isFileCmd (const std::string& cmd) const;
	
	int  CalcAndNote (const std::string& file, bool all, std::vector<SingleWord>&);
	void RunFileQuery (const std::string& cmd);
	void RunWordQuery (const std::string& cmd);
	void SetHistoryNum (const std::string& cmd);
	void RunDelCmd (const std::string& cmd);
	void ShowHistoryByStep();
	void ShowLog();
	void QuitLog();

private:
	Log* log_;	
	bool legal_query_;
};





#endif //QUERY_H